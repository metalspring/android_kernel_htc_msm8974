/*

  Broadcom B43legacy wireless driver

  Copyright (c) 2005 Martin Langer <martin-langer@gmx.de>,
		     Stefano Brivio <stefano.brivio@polimi.it>
		     Michael Buesch <m@bues.ch>
		     Danny van Dyk <kugelfang@gentoo.org>
		     Andreas Jaggi <andreas.jaggi@waterwave.ch>
  Copyright (c) 2007 Larry Finger <Larry.Finger@lwfinger.net>

  Some parts of the code in this file are derived from the ipw2200
  driver  Copyright(c) 2003 - 2004 Intel Corporation.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,
  Boston, MA 02110-1301, USA.

*/

#ifndef B43legacy_PHY_H_
#define B43legacy_PHY_H_

#include <linux/types.h>

enum {
	B43legacy_ANTENNA0,	  
	B43legacy_ANTENNA1,	  
	B43legacy_ANTENNA_AUTO1,  
	B43legacy_ANTENNA_AUTO0,  

	B43legacy_ANTENNA_AUTO	= B43legacy_ANTENNA_AUTO0,
	B43legacy_ANTENNA_DEFAULT = B43legacy_ANTENNA_AUTO,
};

enum {
	B43legacy_INTERFMODE_NONE,
	B43legacy_INTERFMODE_NONWLAN,
	B43legacy_INTERFMODE_MANUALWLAN,
	B43legacy_INTERFMODE_AUTOWLAN,
};


#define B43legacy_PHYROUTE_OFDM_GPHY	0x400
#define B43legacy_PHYROUTE_EXT_GPHY	0x800

#define B43legacy_PHY_BASE(reg)	(reg)
#define B43legacy_PHY_OFDM(reg)	((reg) | B43legacy_PHYROUTE_OFDM_GPHY)
#define B43legacy_PHY_EXTG(reg)	((reg) | B43legacy_PHYROUTE_EXT_GPHY)


#define B43legacy_PHY_CLASSCTL		B43legacy_PHY_EXTG(0x02)	
#define B43legacy_PHY_GTABCTL		B43legacy_PHY_EXTG(0x03)	
#define  B43legacy_PHY_GTABOFF		0x03FF			
#define  B43legacy_PHY_GTABNR		0xFC00			
#define  B43legacy_PHY_GTABNR_SHIFT	10
#define B43legacy_PHY_GTABDATA		B43legacy_PHY_EXTG(0x04)	
#define B43legacy_PHY_LO_MASK		B43legacy_PHY_EXTG(0x0F)	
#define B43legacy_PHY_LO_CTL		B43legacy_PHY_EXTG(0x10)	
#define B43legacy_PHY_RFOVER		B43legacy_PHY_EXTG(0x11)	
#define B43legacy_PHY_RFOVERVAL		B43legacy_PHY_EXTG(0x12)	
#define B43legacy_OFDMTAB(number, offset)				\
			  (((number) << B43legacy_PHY_OTABLENR_SHIFT)	\
			  | (offset))
#define B43legacy_OFDMTAB_AGC1		B43legacy_OFDMTAB(0x00, 0)
#define B43legacy_OFDMTAB_GAIN0		B43legacy_OFDMTAB(0x00, 0)
#define B43legacy_OFDMTAB_GAINX		B43legacy_OFDMTAB(0x01, 0)
#define B43legacy_OFDMTAB_GAIN1		B43legacy_OFDMTAB(0x01, 4)
#define B43legacy_OFDMTAB_AGC3		B43legacy_OFDMTAB(0x02, 0)
#define B43legacy_OFDMTAB_GAIN2		B43legacy_OFDMTAB(0x02, 3)
#define B43legacy_OFDMTAB_LNAHPFGAIN1	B43legacy_OFDMTAB(0x03, 0)
#define B43legacy_OFDMTAB_WRSSI		B43legacy_OFDMTAB(0x04, 0)
#define B43legacy_OFDMTAB_LNAHPFGAIN2	B43legacy_OFDMTAB(0x04, 0)
#define B43legacy_OFDMTAB_NOISESCALE	B43legacy_OFDMTAB(0x05, 0)
#define B43legacy_OFDMTAB_AGC2		B43legacy_OFDMTAB(0x06, 0)
#define B43legacy_OFDMTAB_ROTOR		B43legacy_OFDMTAB(0x08, 0)
#define B43legacy_OFDMTAB_ADVRETARD	B43legacy_OFDMTAB(0x09, 0)
#define B43legacy_OFDMTAB_DAC		B43legacy_OFDMTAB(0x0C, 0)
#define B43legacy_OFDMTAB_DC		B43legacy_OFDMTAB(0x0E, 7)
#define B43legacy_OFDMTAB_PWRDYN2	B43legacy_OFDMTAB(0x0E, 12)
#define B43legacy_OFDMTAB_LNAGAIN	B43legacy_OFDMTAB(0x0E, 13)

#define B43legacy_OFDMTAB_LPFGAIN	B43legacy_OFDMTAB(0x0F, 12)
#define B43legacy_OFDMTAB_RSSI		B43legacy_OFDMTAB(0x10, 0)

#define B43legacy_OFDMTAB_AGC1_R1	B43legacy_OFDMTAB(0x13, 0)
#define B43legacy_OFDMTAB_GAINX_R1	B43legacy_OFDMTAB(0x14, 0)
#define B43legacy_OFDMTAB_MINSIGSQ	B43legacy_OFDMTAB(0x14, 1)
#define B43legacy_OFDMTAB_AGC3_R1	B43legacy_OFDMTAB(0x15, 0)
#define B43legacy_OFDMTAB_WRSSI_R1	B43legacy_OFDMTAB(0x15, 4)
#define B43legacy_OFDMTAB_TSSI		B43legacy_OFDMTAB(0x15, 0)
#define B43legacy_OFDMTAB_DACRFPABB	B43legacy_OFDMTAB(0x16, 0)
#define B43legacy_OFDMTAB_DACOFF	B43legacy_OFDMTAB(0x17, 0)
#define B43legacy_OFDMTAB_DCBIAS	B43legacy_OFDMTAB(0x18, 0)

void b43legacy_put_attenuation_into_ranges(int *_bbatt, int *_rfatt);

#define B43legacy_PHY_VERSION_OFDM	B43legacy_PHY_OFDM(0x00)	
#define B43legacy_PHY_BBANDCFG		B43legacy_PHY_OFDM(0x01)	
#define  B43legacy_PHY_BBANDCFG_RXANT	0x180			
#define  B43legacy_PHY_BBANDCFG_RXANT_SHIFT	7
#define B43legacy_PHY_PWRDOWN		B43legacy_PHY_OFDM(0x03)	
#define B43legacy_PHY_CRSTHRES1		B43legacy_PHY_OFDM(0x06)	
#define B43legacy_PHY_LNAHPFCTL		B43legacy_PHY_OFDM(0x1C)	
#define B43legacy_PHY_ADIVRELATED	B43legacy_PHY_OFDM(0x27)	
#define B43legacy_PHY_CRS0		B43legacy_PHY_OFDM(0x29)
#define B43legacy_PHY_ANTDWELL		B43legacy_PHY_OFDM(0x2B)	
#define  B43legacy_PHY_ANTDWELL_AUTODIV1	0x0100			
#define B43legacy_PHY_ENCORE		B43legacy_PHY_OFDM(0x49)	
#define  B43legacy_PHY_ENCORE_EN	0x0200				
#define B43legacy_PHY_LMS		B43legacy_PHY_OFDM(0x55)
#define B43legacy_PHY_OFDM61		B43legacy_PHY_OFDM(0x61)	
#define  B43legacy_PHY_OFDM61_10	0x0010				
#define B43legacy_PHY_IQBAL		B43legacy_PHY_OFDM(0x69)	
#define B43legacy_PHY_OTABLECTL		B43legacy_PHY_OFDM(0x72)	
#define  B43legacy_PHY_OTABLEOFF	0x03FF				
#define  B43legacy_PHY_OTABLENR		0xFC00				
#define  B43legacy_PHY_OTABLENR_SHIFT	10
#define B43legacy_PHY_OTABLEI		B43legacy_PHY_OFDM(0x73)	
#define B43legacy_PHY_OTABLEQ		B43legacy_PHY_OFDM(0x74)	
#define B43legacy_PHY_HPWR_TSSICTL	B43legacy_PHY_OFDM(0x78)	
#define B43legacy_PHY_NRSSITHRES	B43legacy_PHY_OFDM(0x8A)	
#define B43legacy_PHY_ANTWRSETT		B43legacy_PHY_OFDM(0x8C)	
#define  B43legacy_PHY_ANTWRSETT_ARXDIV	0x2000				
#define B43legacy_PHY_CLIPPWRDOWNT	B43legacy_PHY_OFDM(0x93)	
#define B43legacy_PHY_OFDM9B		B43legacy_PHY_OFDM(0x9B)	
#define B43legacy_PHY_N1P1GAIN		B43legacy_PHY_OFDM(0xA0)
#define B43legacy_PHY_P1P2GAIN		B43legacy_PHY_OFDM(0xA1)
#define B43legacy_PHY_N1N2GAIN		B43legacy_PHY_OFDM(0xA2)
#define B43legacy_PHY_CLIPTHRES		B43legacy_PHY_OFDM(0xA3)
#define B43legacy_PHY_CLIPN1P2THRES	B43legacy_PHY_OFDM(0xA4)
#define B43legacy_PHY_DIVSRCHIDX	B43legacy_PHY_OFDM(0xA8)	
#define B43legacy_PHY_CLIPP2THRES	B43legacy_PHY_OFDM(0xA9)
#define B43legacy_PHY_CLIPP3THRES	B43legacy_PHY_OFDM(0xAA)
#define B43legacy_PHY_DIVP1P2GAIN	B43legacy_PHY_OFDM(0xAB)
#define B43legacy_PHY_DIVSRCHGAINBACK	B43legacy_PHY_OFDM(0xAD)	
#define B43legacy_PHY_DIVSRCHGAINCHNG	B43legacy_PHY_OFDM(0xAE)	
#define B43legacy_PHY_CRSTHRES1_R1	B43legacy_PHY_OFDM(0xC0)	
#define B43legacy_PHY_CRSTHRES2_R1	B43legacy_PHY_OFDM(0xC1)	
#define B43legacy_PHY_TSSIP_LTBASE	B43legacy_PHY_OFDM(0x380)	
#define B43legacy_PHY_DC_LTBASE		B43legacy_PHY_OFDM(0x3A0)	
#define B43legacy_PHY_GAIN_LTBASE	B43legacy_PHY_OFDM(0x3C0)	

void b43legacy_put_attenuation_into_ranges(int *_bbatt, int *_rfatt);

#define B43legacy_PHYVER_ANALOG		0xF000
#define B43legacy_PHYVER_ANALOG_SHIFT	12
#define B43legacy_PHYVER_TYPE		0x0F00
#define B43legacy_PHYVER_TYPE_SHIFT	8
#define B43legacy_PHYVER_VERSION	0x00FF

struct b43legacy_wldev;

void b43legacy_phy_lock(struct b43legacy_wldev *dev);
void b43legacy_phy_unlock(struct b43legacy_wldev *dev);

#define has_loopback_gain(phy)			 \
	(((phy)->rev > 1) || ((phy)->gmode))

u16 b43legacy_phy_read(struct b43legacy_wldev *dev, u16 offset);
void b43legacy_phy_write(struct b43legacy_wldev *dev, u16 offset, u16 val);

int b43legacy_phy_init_tssi2dbm_table(struct b43legacy_wldev *dev);
int b43legacy_phy_init(struct b43legacy_wldev *dev);

void b43legacy_set_rx_antenna(struct b43legacy_wldev *dev, int antenna);

void b43legacy_phy_set_antenna_diversity(struct b43legacy_wldev *dev);
void b43legacy_phy_calibrate(struct b43legacy_wldev *dev);
int b43legacy_phy_connect(struct b43legacy_wldev *dev, int connect);

void b43legacy_phy_lo_b_measure(struct b43legacy_wldev *dev);
void b43legacy_phy_lo_g_measure(struct b43legacy_wldev *dev);
void b43legacy_phy_xmitpower(struct b43legacy_wldev *dev);

void b43legacy_phy_lo_adjust(struct b43legacy_wldev *dev, int fixed);
void b43legacy_phy_lo_mark_all_unused(struct b43legacy_wldev *dev);

void b43legacy_phy_set_baseband_attenuation(struct b43legacy_wldev *dev,
					    u16 baseband_attenuation);

void b43legacy_power_saving_ctl_bits(struct b43legacy_wldev *dev,
				     int bit25, int bit26);

#endif 
