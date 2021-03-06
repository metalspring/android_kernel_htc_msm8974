/*
* cycx_main.c	Cyclades Cyclom 2X WAN Link Driver. Main module.
*
* Author:	Arnaldo Carvalho de Melo <acme@conectiva.com.br>
*
* Copyright:	(c) 1998-2003 Arnaldo Carvalho de Melo
*
* Based on sdlamain.c by Gene Kozin <genek@compuserve.com> &
*			 Jaspreet Singh	<jaspreet@sangoma.com>
*
*		This program is free software; you can redistribute it and/or
*		modify it under the terms of the GNU General Public License
*		as published by the Free Software Foundation; either version
*		2 of the License, or (at your option) any later version.
* ============================================================================
* Please look at the bitkeeper changelog (or any other scm tool that ends up
* importing bitkeeper changelog or that replaces bitkeeper in the future as
* main tool for linux development).
* 
* 2001/05/09	acme		Fix MODULE_DESC for debug, .bss nitpicks,
* 				some cleanups
* 2000/07/13	acme		remove useless #ifdef MODULE and crap
*				#if KERNEL_VERSION > blah
* 2000/07/06	acme		__exit at cyclomx_cleanup
* 2000/04/02	acme		dprintk and cycx_debug
* 				module_init/module_exit
* 2000/01/21	acme		rename cyclomx_open to cyclomx_mod_inc_use_count
*				and cyclomx_close to cyclomx_mod_dec_use_count
* 2000/01/08	acme		cleanup
* 1999/11/06	acme		cycx_down back to life (it needs to be
*				called to iounmap the dpmbase)
* 1999/08/09	acme		removed references to enable_tx_int
*				use spinlocks instead of cli/sti in
*				cyclomx_set_state
* 1999/05/19	acme		works directly linked into the kernel
*				init_waitqueue_head for 2.3.* kernel
* 1999/05/18	acme		major cleanup (polling not needed), etc
* 1998/08/28	acme		minor cleanup (ioctls for firmware deleted)
*				queue_task activated
* 1998/08/08	acme		Initial version.
*/

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/stddef.h>	
#include <linux/errno.h>	
#include <linux/string.h>	
#include <linux/slab.h>		
#include <linux/kernel.h>	
#include <linux/module.h>	
#include <linux/ioport.h>	
#include <linux/wanrouter.h>	
#include <linux/cyclomx.h>	
#include <linux/init.h>         
#include <linux/interrupt.h>

unsigned int cycx_debug;

MODULE_AUTHOR("Arnaldo Carvalho de Melo");
MODULE_DESCRIPTION("Cyclom 2X Sync Card Driver.");
MODULE_LICENSE("GPL");
module_param(cycx_debug, int, 0);
MODULE_PARM_DESC(cycx_debug, "cyclomx debug level");


#define	CYCX_DRV_VERSION	0	
#define	CYCX_DRV_RELEASE	11	
#define	CYCX_MAX_CARDS		1	

#define	CONFIG_CYCX_CARDS 1


static int cycx_wan_setup(struct wan_device *wandev, wandev_conf_t *conf);
static int cycx_wan_shutdown(struct wan_device *wandev);

static irqreturn_t cycx_isr(int irq, void *dev_id);


static const char cycx_drvname[] = "cyclomx";
static const char cycx_fullname[] = "CYCLOM 2X(tm) Sync Card Driver";
static const char cycx_copyright[] = "(c) 1998-2003 Arnaldo Carvalho de Melo "
			  "<acme@conectiva.com.br>";
static int cycx_ncards = CONFIG_CYCX_CARDS;
static struct cycx_device *cycx_card_array;	


static int __init cycx_init(void)
{
	int cnt, err = -ENOMEM;

	pr_info("%s v%u.%u %s\n",
		cycx_fullname, CYCX_DRV_VERSION, CYCX_DRV_RELEASE,
		cycx_copyright);

	
	cycx_ncards = min_t(int, cycx_ncards, CYCX_MAX_CARDS);
	cycx_ncards = max_t(int, cycx_ncards, 1);
	cycx_card_array = kcalloc(cycx_ncards, sizeof(struct cycx_device), GFP_KERNEL);
	if (!cycx_card_array)
		goto out;


	
	for (cnt = 0; cnt < cycx_ncards; ++cnt) {
		struct cycx_device *card = &cycx_card_array[cnt];
		struct wan_device *wandev = &card->wandev;

		sprintf(card->devname, "%s%d", cycx_drvname, cnt + 1);
		wandev->magic    = ROUTER_MAGIC;
		wandev->name     = card->devname;
		wandev->private  = card;
		wandev->setup    = cycx_wan_setup;
		wandev->shutdown = cycx_wan_shutdown;
		err = register_wan_device(wandev);

		if (err) {
			pr_err("%s registration failed with error %d!\n",
			       card->devname, err);
			break;
		}
	}

	err = -ENODEV;
	if (!cnt) {
		kfree(cycx_card_array);
		goto out;
	}
	err = 0;
	cycx_ncards = cnt;	
out:	return err;
}

static void __exit cycx_exit(void)
{
	int i = 0;

	for (; i < cycx_ncards; ++i) {
		struct cycx_device *card = &cycx_card_array[i];
		unregister_wan_device(card->devname);
	}

	kfree(cycx_card_array);
}

static int cycx_wan_setup(struct wan_device *wandev, wandev_conf_t *conf)
{
	int rc = -EFAULT;
	struct cycx_device *card;
	int irq;

	

	if (!wandev || !wandev->private || !conf)
		goto out;

	card = wandev->private;
	rc = -EBUSY;
	if (wandev->state != WAN_UNCONFIGURED)
		goto out;

	rc = -EINVAL;
	if (!conf->data_size || !conf->data) {
		pr_err("%s: firmware not found in configuration data!\n",
		       wandev->name);
		goto out;
	}

	if (conf->irq <= 0) {
		pr_err("%s: can't configure without IRQ!\n", wandev->name);
		goto out;
	}

	
	irq = conf->irq == 2 ? 9 : conf->irq;	

	if (request_irq(irq, cycx_isr, 0, wandev->name, card)) {
		pr_err("%s: can't reserve IRQ %d!\n", wandev->name, irq);
		goto out;
	}

	
	memset(&card->hw, 0, sizeof(card->hw));
	card->hw.irq	 = irq;
	card->hw.dpmsize = CYCX_WINDOWSIZE;
	card->hw.fwid	 = CFID_X25_2X;
	spin_lock_init(&card->lock);
	init_waitqueue_head(&card->wait_stats);

	rc = cycx_setup(&card->hw, conf->data, conf->data_size, conf->maddr);
	if (rc)
		goto out_irq;

	
	wandev->irq       = irq;
	wandev->dma       = wandev->ioport = 0;
	wandev->maddr     = (unsigned long)card->hw.dpmbase;
	wandev->msize     = card->hw.dpmsize;
	wandev->hw_opt[2] = 0;
	wandev->hw_opt[3] = card->hw.fwid;

	
	switch (card->hw.fwid) {
#ifdef CONFIG_CYCLOMX_X25
	case CFID_X25_2X:
		rc = cycx_x25_wan_init(card, conf);
		break;
#endif
	default:
		pr_err("%s: this firmware is not supported!\n", wandev->name);
		rc = -EINVAL;
	}

	if (rc) {
		cycx_down(&card->hw);
		goto out_irq;
	}

	rc = 0;
out:
	return rc;
out_irq:
	free_irq(irq, card);
	goto out;
}

static int cycx_wan_shutdown(struct wan_device *wandev)
{
	int ret = -EFAULT;
	struct cycx_device *card;

	
	if (!wandev || !wandev->private)
		goto out;

	ret = 0;
	if (wandev->state == WAN_UNCONFIGURED)
		goto out;

	card = wandev->private;
	wandev->state = WAN_UNCONFIGURED;
	cycx_down(&card->hw);
	pr_info("%s: irq %d being freed!\n", wandev->name, wandev->irq);
	free_irq(wandev->irq, card);
out:	return ret;
}

static irqreturn_t cycx_isr(int irq, void *dev_id)
{
	struct cycx_device *card = dev_id;

	if (card->wandev.state == WAN_UNCONFIGURED)
		goto out;

	if (card->in_isr) {
		pr_warn("%s: interrupt re-entrancy on IRQ %d!\n",
			card->devname, card->wandev.irq);
		goto out;
	}

	if (card->isr)
		card->isr(card);
	return IRQ_HANDLED;
out:
	return IRQ_NONE;
}

void cycx_set_state(struct cycx_device *card, int state)
{
	unsigned long flags;
	char *string_state = NULL;

	spin_lock_irqsave(&card->lock, flags);

	if (card->wandev.state != state) {
		switch (state) {
		case WAN_CONNECTED:
			string_state = "connected!";
			break;
		case WAN_DISCONNECTED:
			string_state = "disconnected!";
			break;
		}
		pr_info("%s: link %s\n", card->devname, string_state);
		card->wandev.state = state;
	}

	card->state_tick = jiffies;
	spin_unlock_irqrestore(&card->lock, flags);
}

module_init(cycx_init);
module_exit(cycx_exit);
