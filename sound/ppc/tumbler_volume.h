static unsigned int master_volume_table[] = {
	0x00000015, 0x00000016,	0x00000017,
	0x00000019, 0x0000001a,	0x0000001c,
	0x0000001d, 0x0000001f,	0x00000021,
	0x00000023, 0x00000025,	0x00000027,
	0x00000029, 0x0000002c,	0x0000002e,
	0x00000031, 0x00000034,	0x00000037,
	0x0000003a, 0x0000003e,	0x00000042,
	0x00000045, 0x0000004a,	0x0000004e,
	0x00000053, 0x00000057,	0x0000005d,
	0x00000062, 0x00000068,	0x0000006e,
	0x00000075, 0x0000007b,	0x00000083,
	0x0000008b, 0x00000093,	0x0000009b,
	0x000000a5, 0x000000ae,	0x000000b9,
	0x000000c4, 0x000000cf,	0x000000dc,
	0x000000e9, 0x000000f6,	0x00000105,
	0x00000114, 0x00000125,	0x00000136,
	0x00000148, 0x0000015c,	0x00000171,
	0x00000186, 0x0000019e,	0x000001b6,
	0x000001d0, 0x000001eb,	0x00000209,
	0x00000227, 0x00000248,	0x0000026b,
	0x0000028f, 0x000002b6,	0x000002df,
	0x0000030b, 0x00000339,	0x0000036a,
	0x0000039e, 0x000003d5,	0x0000040f,
	0x0000044c, 0x0000048d,	0x000004d2,
	0x0000051c, 0x00000569,	0x000005bb,
	0x00000612, 0x0000066e,	0x000006d0,
	0x00000737, 0x000007a5,	0x00000818,
	0x00000893, 0x00000915,	0x0000099f,
	0x00000a31, 0x00000acc,	0x00000b6f,
	0x00000c1d, 0x00000cd5,	0x00000d97,
	0x00000e65, 0x00000f40,	0x00001027,
	0x0000111c, 0x00001220,	0x00001333,
	0x00001456, 0x0000158a,	0x000016d1,
	0x0000182b, 0x0000199a,	0x00001b1e,
	0x00001cb9, 0x00001e6d,	0x0000203a,
	0x00002223, 0x00002429,	0x0000264e,
	0x00002893, 0x00002afa,	0x00002d86,
	0x00003039, 0x00003314,	0x0000361b,
	0x00003950, 0x00003cb5,	0x0000404e,
	0x0000441d, 0x00004827,	0x00004c6d,
	0x000050f4, 0x000055c0,	0x00005ad5,
	0x00006037, 0x000065ea,	0x00006bf4,
	0x0000725a, 0x00007920,	0x0000804e,
	0x000087e8, 0x00008ff6,	0x0000987d,
	0x0000a186, 0x0000ab19,	0x0000b53c,
	0x0000bff9, 0x0000cb59,	0x0000d766,
	0x0000e429, 0x0000f1ae,	0x00010000,
	0x00010f2b, 0x00011f3d,	0x00013042,
	0x00014249, 0x00015562,	0x0001699c,
	0x00017f09, 0x000195bc,	0x0001adc6,
	0x0001c73d, 0x0001e237,	0x0001feca,
	0x00021d0e, 0x00023d1d,	0x00025f12,
	0x0002830b, 0x0002a925,	0x0002d182,
	0x0002fc42, 0x0003298b,	0x00035983,
	0x00038c53, 0x0003c225,	0x0003fb28,
	0x0004378b, 0x00047783,	0x0004bb44,
	0x0005030a, 0x00054f10,	0x00059f98,
	0x0005f4e5, 0x00064f40,	0x0006aef6,
	0x00071457, 0x00077fbb,	0x0007f17b,
};

static unsigned int treble_volume_table[] = {
	0x96, 0x95, 0x94,
	0x93, 0x92, 0x91,
	0x90, 0x8f, 0x8e,
	0x8d, 0x8c, 0x8b,
	0x8a, 0x89, 0x88,
	0x87, 0x86, 0x85,
	0x84, 0x83, 0x82,
	0x81, 0x80, 0x7f,
	0x7e, 0x7d, 0x7c,
	0x7b, 0x7a, 0x79,
	0x78, 0x77, 0x76,
	0x75, 0x74, 0x73,
	0x72, 0x71, 0x70,
	0x6e, 0x6d, 0x6c,
	0x6b, 0x69, 0x68,
	0x66, 0x65, 0x63,
	0x62, 0x60, 0x5e,
	0x5c, 0x5a, 0x57,
	0x55, 0x52, 0x4f,
	0x4c, 0x49, 0x45,
	0x42, 0x3e, 0x3a,
	0x36, 0x32, 0x2d,
	0x28, 0x22, 0x1c,
	0x16, 0x10, 0x09,
	0x01,
};

static unsigned int bass_volume_table[] = {
	0x86, 0x82, 0x7f,
	0x7d, 0x7a, 0x78,
	0x76, 0x74, 0x72,
	0x70, 0x6e, 0x6d,
	0x6b, 0x69, 0x66,
	0x64, 0x61, 0x5f,
	0x5d, 0x5c, 0x5a,
	0x59, 0x58, 0x56,
	0x55, 0x54, 0x53,
	0x51, 0x4f, 0x4d,
	0x4b, 0x49, 0x46,
	0x44, 0x42, 0x40,
	0x3e, 0x3c, 0x3b,
	0x39, 0x38, 0x36,
	0x35, 0x33, 0x31,
	0x30, 0x2e, 0x2c,
	0x2b, 0x29, 0x28,
	0x26, 0x25, 0x23,
	0x21, 0x1f, 0x1c,
	0x19, 0x18, 0x17,
	0x16, 0x14, 0x13,
	0x12, 0x10, 0x0f,
	0x0d, 0x0b, 0x0a,
	0x08, 0x06, 0x03,
	0x01,
};

static unsigned int mixer_volume_table[] = {
	0x00014b, 0x00015f, 0x000174,
	0x00018a, 0x0001a1, 0x0001ba,
	0x0001d4, 0x0001f0, 0x00020d,
	0x00022c, 0x00024d, 0x000270,
	0x000295, 0x0002bc, 0x0002e6,
	0x000312, 0x000340, 0x000372,
	0x0003a6, 0x0003dd, 0x000418,
	0x000456, 0x000498, 0x0004de,
	0x000528, 0x000576, 0x0005c9,
	0x000620, 0x00067d, 0x0006e0,
	0x000748, 0x0007b7, 0x00082c,
	0x0008a8, 0x00092b, 0x0009b6,
	0x000a49, 0x000ae5, 0x000b8b,
	0x000c3a, 0x000cf3, 0x000db8,
	0x000e88, 0x000f64, 0x00104e,
	0x001145, 0x00124b, 0x001361,
	0x001487, 0x0015be, 0x001708,
	0x001865, 0x0019d8, 0x001b60,
	0x001cff, 0x001eb7, 0x002089,
	0x002276, 0x002481, 0x0026ab,
	0x0028f5, 0x002b63, 0x002df5,
	0x0030ae, 0x003390, 0x00369e,
	0x0039db, 0x003d49, 0x0040ea,
	0x0044c3, 0x0048d6, 0x004d27,
	0x0051b9, 0x005691, 0x005bb2,
	0x006121, 0x0066e3, 0x006cfb,
	0x007370, 0x007a48, 0x008186,
	0x008933, 0x009154, 0x0099f1,
	0x00a310, 0x00acba, 0x00b6f6,
	0x00c1cd, 0x00cd49, 0x00d973,
	0x00e655, 0x00f3fb, 0x010270,
	0x0111c0, 0x0121f9, 0x013328,
	0x01455b, 0x0158a2, 0x016d0e,
	0x0182af, 0x019999, 0x01b1de,
	0x01cb94, 0x01e6cf, 0x0203a7,
	0x022235, 0x024293, 0x0264db,
	0x02892c, 0x02afa3, 0x02d862,
	0x03038a, 0x033142, 0x0361af,
	0x0394fa, 0x03cb50, 0x0404de,
	0x0441d5, 0x048268, 0x04c6d0,
	0x050f44, 0x055c04, 0x05ad50,
	0x06036e, 0x065ea5, 0x06bf44,
	0x07259d, 0x079207, 0x0804dc,
	0x087e80, 0x08ff59, 0x0987d5,
	0x0a1866, 0x0ab189, 0x0b53be,
	0x0bff91, 0x0cb591, 0x0d765a,
	0x0e4290, 0x0f1adf, 0x100000,
	0x10f2b4, 0x11f3c9, 0x13041a,
	0x14248e, 0x15561a, 0x1699c0,
	0x17f094, 0x195bb8, 0x1adc61,
	0x1c73d5, 0x1e236d, 0x1fec98,
	0x21d0d9, 0x23d1cd, 0x25f125,
	0x2830af, 0x2a9254, 0x2d1818,
	0x2fc420, 0x3298b0, 0x35982f,
	0x38c528, 0x3c224c, 0x3fb278,
	0x437880, 0x477828, 0x4bb446,
	0x5030a1, 0x54f106, 0x59f980,
	0x5f4e52, 0x64f403, 0x6aef5d,
	0x714575, 0x77fbaa, 0x7f17af,
};


static unsigned int snapper_treble_volume_table[] = {
	0x96, 0x95, 0x94,
	0x93, 0x92, 0x91,
	0x90, 0x8f, 0x8e,
	0x8d, 0x8c, 0x8b,
	0x8a, 0x89, 0x88,
	0x87, 0x86, 0x85,
	0x84, 0x83, 0x82,
	0x81, 0x80, 0x7f,
	0x7e, 0x7d, 0x7c,
	0x7b, 0x7a, 0x79,
	0x78, 0x77, 0x76,
	0x75, 0x74, 0x73,
	0x72, 0x71, 0x70,
	0x6f, 0x6d, 0x6c,
	0x6b, 0x69, 0x68,
	0x67, 0x65, 0x63,
	0x62, 0x60, 0x5d,
	0x5b, 0x59, 0x56,
	0x53, 0x51, 0x4d,
	0x4a, 0x47, 0x43,
	0x3f, 0x3b, 0x36,
	0x31, 0x2c, 0x26,
	0x20, 0x1a, 0x13,
	0x08, 0x04, 0x01,
	0x01,
};

static unsigned int snapper_bass_volume_table[] = {
	0x96, 0x95, 0x94,
	0x93, 0x92, 0x91,
	0x90, 0x8f, 0x8e,
	0x8d, 0x8c, 0x8b,
	0x8a, 0x89, 0x88,
	0x87, 0x86, 0x85,
	0x84, 0x83, 0x82,
	0x81, 0x80, 0x7f,
	0x7e, 0x7d, 0x7c,
	0x7b, 0x7a, 0x79,
	0x78, 0x77, 0x76,
	0x75, 0x74, 0x73,
	0x72, 0x71, 0x6f,
	0x6e, 0x6d, 0x6b,
	0x6a, 0x69, 0x67,
	0x66, 0x65, 0x63,
	0x62, 0x61, 0x5f,
	0x5d, 0x5b, 0x58,
	0x55, 0x52, 0x4f,
	0x4c, 0x49, 0x46,
	0x43, 0x3f, 0x3b,
	0x37, 0x33, 0x2e,
	0x29, 0x24, 0x1e,
	0x18, 0x11, 0x0a,
	0x01,
};

