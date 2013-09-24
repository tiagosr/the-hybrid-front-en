// Hybrid Front disassembly function/data regions index

void start() = 0x000200;

// some init data from 294 to 2ff

void _000300();
void _00047a();
void _000490();
void _0004a4();
void _0004e0();
void _0004f6();

// some uint16_t from 544 to 54a

void _00054c();
void _000592();
void _0005be();
void _0005ee();
// next 3 look very similar
void _000620();
void _00063c();
void _00065c();

void _00067c();
void _0006a8();

void _0006c2() { // busy loop while waiting for interrupt?
	_ff0104[0].w = _ff010e[0]
	while(_ff0104[0]); 
}

void _0006d6();

uint16_t _000754[5];

void _00075e();
void _00077e();
void _0007f6();

void _000854() { _000490(); }
void _00085c();

void _000882();
void _000910();
void _000924();
void _000982();
void _000996();

// huge megazord function
void _0009c2();
void _000c24();

// some data fro 000cce to 000d80

void _000d82() {
	_0015a0();
	_000490();
	_001018(128, 0, -3328);
	_00158e();
}

// some data from 000da6 to 000f80 - function table?

void _000f82() {}

// function table from 000f84 to 001014
void (*_000f84())[37] = {
	_0281a8,
    _0281e8,
    _000f82,
    _028316,
    _028434,
    _0286f6,
    _028858,
    _028a7a,
    _028f44,
    _028ffc,
    _02908a,
    _02931a,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _000f82,
    _010590,
    _01068a,
    _010b5a,
    _010d8e,
    _0aaad0,
    _0aaa78,
    _0aaa06,
    _0aa97c,

    _ff9000,
    _ff9030,
    _ff9060,
    _ff9030,
}

void _001018(uint16_t, uint32_t, uint16_t);

void _00109e();

void _00119a(); //// updates VDP
void _0011d6(); //// updates de VDP
void _0011ea() {
	for(i = 0; i < 192; i++) {
		_ffff00[i] = 0;
	}
}

//// série de funções bem parecidas, com update de VDP
void _0011fc();
void _001246();
void _0012a2();
void _0012ec();
void _001336();
void _001380();
void _001414();
void _00145e();
void _0014ac();
void _0014fa();
void _001544();

void _00158e();

void _0015a0() { // updates vdp: set mode from info at _ff0413 disabling display
	d0.w = 0x8100; // write register 1
	d0.b = _ff0413[0] & 0xbf; // filter out DISP (d6)
	VDP_CTRL[0] = d0;
}

void _0015b6() {
	for(size_t i = 0; i < 19; i++) {
		_ff0410[i] = _00162e[i];
	}
	_ff043e = 0xb000;
	_ff043a = 0xc000;
	_ff043c = 0xe000;
	_ff0442 = 0xa800;
	_ff0440 = 0xac00;
}
void _0015f2() {
	for(size_t i = 0; i < 19; i++) {
		_ff0410[i] = _001654[i];
	}
	_ff043e = 0xd000;
	_ff043a = 0xc000;
	_ff043c = 0xe000;
	_ff0442 = 0xf800;
	_ff0440 = 0xf400;
}
uint16_t _00162e[19];
uint16_t _001654[19];

void _00167a() {
	for(size_t i = 0; i < 19; i++) {
		VDP_CTRL = _ff0410[i];
	}
}

void _001690();
void _0016ac(void*a0) {
	void *a1 = a0[0]
	for(size_t i = 0; i < 16; i++) {
		a1[i] = 0;
	}
}
void _0016c2();
void _0016fe();
void _001774();
void _00179c();

void _001898(); // jumps around a bit

void _001baa();
void _001c1e();
void _001c98();
void _001ca6();
void _001cb4();
void _001cc6();
void _001cd8();

void _001ce6();

void _001d62();

void _001d76();

void _001e16();
void _001e54();

void _001e76() { // this looks like a decoder
	push(d0,d1,d2,d3,d4,d5,d6,d7,a0,a1,a3,a4,a5)
	a3 = _001f08;
	a4 = VDP_DATA;
	*_ff011e &= 0xfffffffe; // clear bit 0
	goto _001e9a:

_001e9a:
	a1 = _ff3000;
	d2.w = *(a0); a0 += 2;
	if(carry_clear(d2.w += d2.w)) {
		a3 += 10;
	}
	d2.w += d2.w;
	d2.w += d2.w;
	a5.w = d2;
	d3 = 8;
	d2 = 0;
	d4 = 0;
	_001f40(d2, d3, d4, a0, a1);
	_001fc2();
	d0 = 8;
	d1 = _001fcc(d0, d5, d6);
	if(d1.w < 252) {
		//d1.w += d1.w;
		d0 = _ff3000[d1.w];
		sign_extend_word(d0);
		_001fe0();
	}// _001efa

	pop(d0,d1,d2,d3,d4,d5,d6,d7,a0,a1,a3,a4,a5)
}

void _001f40(d2, d3, d4, a0, a1);
void _001fb6();

void _001fc2(a0) { // reverse a word, result on d5
	d5.w = *(a0++).b << 8 | *(a0++).b;
	d6 = 16;
}

uint16_t _001fcc(d0, d5, d6) { // masks bits for the decoders?
	d7.w = d6.w - d0.w;
	d1.w = d5.w;
	d1.w <<= d7;
	//d0.w += d0.w;
	d1.w &= _001ff0_word_mask[d0];
	return d1.w;
}

void _001fdc(d0, d5, d6) {
	d1.w = _001fcc(d0, d5, d6);
	d0.w <<= 1;
	return _001fe0(d0, d5, d6); 
}

void _001fe0(d0, d5, d6) { // shift new byte into D5 for decoding?
	d6.w -= d0.w;
	if (d6 < 9) {
		d6 += 8;
		asl(d5,8);
		d5 = *(a0++);
	}
}

uint16_t _001ff0_word_mask[16] {
	0x0001,
	0x0003,
	0x0007,
	0x000f,
	0x001f,
	0x003f,
	0x007f,
	0x00ff,
	0x01ff,
	0x03ff,
	0x07ff,
	0x0fff,
	0x1fff,
	0x3fff,
	0x7fff,
	0xffff
}

void _002010();

// data region from 2129 to 21b5

void _00212a();

void _0021b6();

void _0021ec();

void _002264();

//void _002272(); //?

void _002280();

void _0022aa();

uint8_t _00231c[30];

void _00233a();

uint16_t _0024fe[2];

void _002502();

uint16_t _002532[34];

void _002576();

uint16_t _0025f8[4];

void _002600();

void (*_002624())[7] = {
	_002640,
	_00268e,
	_0026c8,
	_002678,
	_0027ea,
	_00287e,
	_00293c,
};

void _002640();
void _00268e();
void _0026c8();
void _002768();
void _0027ea();
void _00287e();
void _00293c();

void _002982();

void (*_00299c())[7] = {
	_0029b8,
	_0029ee,
	_002a30,
	_002c12,
	_002c76,
	_002d22,
	_002e0c,
}

void _0029b8();
void _0029ee();
void _002a30();
void _002c12();
void _002c76();
void _002d22();
void _002e0c();

void _002e40();
void _002f90();
void _002fd6();
void _00301c();
void _0030a2();
void _003116();
void _003148();
void _00317a();
void _0031ac();
void _003282();
void _0032fa();
void _0033e8();
void _00343e();
void _003452();
void _003466();
void _0034a2(uint16_t d7);
uint32_t _0034c0(uint8_t d6, uint8_t *a0);
void _0034d8(uint16_t d0);

void (*_00352e())[3] = {
	_00353a,
	_003556,
	_003572
}

void _00353a();
void _003556();
void _003572();

uint16_t _00358e[20];

uint16_t *_0035b6[3] = {
	_0035c2,
	_0035c8,
	_0035d4
}

uint16_t _0035c2[3];
uint16_t _0035c8[6];
uint16_t _0035d4[11];

void _0035ea();
void _00360c() { _002982(); }
void _003614();
void _003680();
void _00375c() { _002600(); }

void (*_003764())[4] = {
	_00378e,
	_0037be,
	_003774,
	_0037a4
}

void _003774() {
	_0037a4;
	_00378e:
	_0037be:
}

uint8_t _003834[0x3658-0x3834]; // big chunk of data

void _003c58();
void _003cae();

uint16_t _003d02[12];

void _003d1a();
void _003d24();

uint16_t _003de4[26];

void _003e18();
void _003e46();
void _003e7c();

uint16_t _003eee[40];

void _003f3e();
void _003f82();

void _003f82(); // preloads some data to ff2000-ff2024, then jumps to 035604

void _004022();
void _00406c();
void _0040b6();
void _004100();

void _00414a() { _00406c();}
void _004152();
void _004180();
void _0041b2();
void _0041ea();
void _004214();

uint16_t _00423e[0x4414-0x423e]; // big chunk of data

void (*_004414())[23] = {
	_00534e,
	_004752,
	_00480e,
	_00483c,
	_004848,
	_004872,
	_004894,
	_0048cc,
	_004a5c,
	_004b18,
	_004be2,
	_004c4a,
	_004ca6,
	_004cb2,
	_004cb4,
	_004cb6,
	_004d94,
	_004e3e,
	_004efe,
	_005060,
	_0051aa,
	_005318,
	_005358
}

void _004470();
void _004694();
void _004704();

void _004752();
void _004766();
void _0047e2();
void _00480e();
void _004848();
void _004872();
void _004894();

uint16_t _0048e0[6];

void _0048ec();
void _00494c();
void _0049ac();
void _0049da();
void _004a08();
void _004a36();
void _004a5c();
void _004a70();
void _004ac2();
void _004b18();
void _004b2c();
void _004b8c();
void _004be2();
void _004c4a();
void _004cb2() {}
void _004cb4() {}
void _004cb6();

uint16_t _004cca[2];

void _004cce();
void _004d50();
void _004d94();
void _004da8();
void _004dfe();
void _004e3e();
void _004e52();
void _004eb6();
void _004efe();

uint16_t _004f12[6];

void _004f1e() { _ff2034++; }
void _004f26();
void _004f54();
void _004fac();
void _004fe2();
void _004ffe();
void _005060();

uint16_t _005074[14];

void _005090();
void _0050a6();
void _0050fe();
void _005182();
void _0051aa();

uint16_t _0051be[2];

void _0051c2();
void _005274();
void _005304();
void _005318();

uint16_t _00532c[2];

void _005330();
void _00533e();
void _00534e();
void _005358();
void _00535a();
void _00541a();
void _005432();
void _005426();
void _0054f2();
void _0054f6();
void _005640();
void _00565c();
void _0056a4();
void _0056fc();

void _005716() { // seems linked to audio stuff, might be music related
	while (true) {
		_ff010e[0].w = 24;
		d0.w = _ff200e[0];
		if((d0.w & 1) == 0) {
			a0 = _fff300;
			a1 = _fff300;
			_0057b8(a0, a1);
		}
		_ff200e[0].w += 1;
		if(_ff200e[0].w > 16) {
			_ff200e[0] = 0;
			return _0015a0();
		}
		_0006c2();
	}
}

void _00575c();
void _0057b8();
void _0057f0();

void _005aa6();

void _005c22();
void _005c54();
void _005c88();

void _005d18(); // updates VDP
void _005d64(); // updates VDP

void _005d8c();
void _005da0();
void _005db4();
void _005dec();
void _005e1a(uint32_t d0) {
	while (d0-- > 0) {
		_0006c2();
	}
}

void _005e26();
void _005e3a();
void _005e6c();
void _005f42();

uint16_t _005f84[0xf4-0x84];

void _005ff4();

void _0060f2(); // looks like some decompression/decryption routine. gfx decompression?

void _0062b6();
void _00632c();
void _006338();
void _006342();
void _006352();

uint16_t _006366[16];

void _006386();
void _0063d4();
void _006480();
void _006538();
void _00666c();

uint16_t _006768[0x94-0x68];

void _006798();
void _006806();
void _00682c();

uint16_t _006870[0xc8-0x70];

void _0068ce();
void _0068de();

uint16_t _006924[0x6c-0x24];

void _006970(); // another decompression routine? loops around itself

void _006a56();
void _006b26();
void _006bb8();
void _006c16() {
	_ff2000 &= 0xffff0000;
}

void _006c1e(); // huge ass routine

uint16_t _006e60[0x94-0x60];

void _006e98();

void _006f12();

void _006f2a();
void _006f62();
void _007036();
void _0070ce();

void _007152() {
	d0.w = (fp[-4] - 32)<<1
	fp[-4] = _007164[d0.w]
}

uint16_t _007164[6];

void _007170() {
	d7 = 0xc0000000;
	d6.w = 0;
	d5.w = 127;
	_0011d6(d5, d6, d7); // this updates vdp
	a2 = 0xfff300;
	d0 = 63;
	do {
		*(a2++) = 0;
	} while (d0--);
}

void _007192() {
	fp = _ff2220;
	d0 = 8;
	d1 = -1;
	do {
		*(fp++) = d1
	} while(d0--);
}

void _0071a4() {
	fp = _ff2800;
	a5 = _0071ba;
	d7 = 39;
	do {
		*(fp++) = *(a5++);
	} while (d0--);
}

uint16_t _0071ba[40];

void _007230();
void _00737e();
void _0074a2();
void _0075da();
void _007654();
void _00771e();
void _0077ba();

void _007898() {}

void _00789a(d1, d2, d7, a0, a1) {
	do{
		d4 = d1;
		do {
			*(a0) = *(a1);
			a0+=4; a1+=4;
		} while(d4--);
		a0 += d7;
	} while(d2--);
}

void _0078aa(d1, d2, d3, a0, a1) {
	do{
		d4 = d1;
		do {
			*(a0) = *(a1) + d3;
			a0+=4; a1+=4;
		} while(d4--);
		a0 += 116;
	} while(d2--);
}

void _0078c0();

uint16_t _00799a[0xc2-0x9a];

void _0079c2() {
	d0 = _ff2038[0] * 4;
	
	*(a0) += d0;
}

void _0079d6();
void _007a08();
void _007a42();
void _007a64();

uint16_t _007caa[0xf0 - 0xaa];

void _007cf2();
void _007dbe();
void _007e06() {
	_0079c2();
	d1 = 0;
	d1.w = a0[0];
	d3 = d1;
	d1 *= 8;
	a1 = 0x8454e;
	a1 += d1;
	d0 = 7;
	fp = 0xff39bc;
	_007f40(d0, a1, fp);
}

void _007e2c() { // z80 communication? sound code?
	_0079c2();
	d1 = 0;
	d1.w = a0[0];
	a1 = 0x1440a8;
	d1 <<= 2
	a0 = a1[d1];
	if(a0) {
		a0 = _001e54(1664, a0)
		return _001e76();
	} else {
		*(0xa11100) = 256;
		d7 = 0x5000003;
		d6.w = 0;
		d5.w = 1342;
		_0011d6(d5, d6, d7);
		*(0xa11100) = 0;
	}
}

void _007e7e();
void _007ec6();
void _007efc();

void _007f40() {
	d2 = 29;
	do {
		d1 = 0;
		d1.b = *(a1)
		a1 += 1;
		d1 += 1;
		*(fp).w = d1;
		fp += 2;		
	} while(d2--);
}

void _007f54();

void _008000();

uint16_t _00806c[0xaa - 0x6c];

void _0080aa();
void _008212();
void _00824a() {
	d0.w = _ff2006[0];
	d0 &= 63;
	a0 = _008262[d0]
	goto *a0;
}

void *(_008262)() [7] = {
	_00827e,
	_0083ca,
	_0084b6,
	_0085bc,
	_0086b8,
	_008798,
	_008972,
}

void _00827e() {
	_ff2006[0] |= 1<<7;
	if(_ff2006[0]) goto _008394;
	if(_ff0502[0] == 1) goto _0082d0;
	if(_ff0502[0] == 6) goto _0082d0;
	if(_ff0502[0] == 10) goto _0082d0;
	if(_ff0502[0] == 14) goto _0082d0;
	if(_ff0502[0] == 21) goto _0082d0;
	_ff2006[0] = 8;
}


///// bunch of functions that look like they set up different kinds of screens

void _0082d0() {
	//.....

	_ff2030[0].w = 0;
	_005716();
	_0015a0();
	_ff010e[0].w = 28;
	_ff2006[0].w = 4;
}

void _0083ca() {
	//....

	d0.w = 160;
	_027f5e(d0);
	_ff2030[0].w = 0;
	_005716();
	_0015a0();
	_ff010e[0].w = 28;
	_ff2006[0].w = 8;
}

void _0084b6() {
	//....

	_ff2030[0].w = 0;
	_005716();
	_0015a0();
	_ff010e[0].w = 28;
	_ff2006[0].w = 12;
}

void _0085bc();
void _0086b8();
void _008798();
void _0088e8();

void _0089a2(d7, a1, a2) {
	do {
		d2 = 0x801e;
		d1 = 0;
		d1.b = *(a2++);
		d1 += d2;
		*(a1).w = d1;
		a1+=2;		
	}while(d7--)
}

void _0089b6() {
	_0015a0();
	d7 = 0x63c00000;
	d6.w = 0;
	d5.w = 0x3fff;
	_0011d6(d5, d6, d7);
	_00158e();
}

void (*_0089d8)()[19] {
	_008aac,
	_008ab4,
	_008c2c,
	_008dc8,
	_008f64,
	_009014,
	_00910a,
	_00918a,
	_0091d4,
	_009244,
	_0093d6,
	_0094f8,
	_0095c4,
	_009680,
	_00985e,
	_009a6c,
	_009ba6,
	_009caa,
	_009d92,
}

void _008a24();

void _008aac() {
	_ff2032[0] += 2;
}

void _008ab4();
void _008c2c();
void _008dc8();

////////////////~~~~~~~~~~~~~~~~~~~~~~////////////////////

void _03a3a2() {
	a0 = _1d0dcc;
	d0.w = *_ff2082;
	//d0 <<= 2;
	a0 = _1d0dcc[d0];
	sr |= 0x0700; // disable ints
	VDP_CTRL = 0x70000001; // VRAM write, address 0x7000
	_001e76();
	sr &= 0xf8ff; // enable ints
}

void _03a3ce() {
	a0 = _1d3200;
	d0.w = *_ff2082;
	//d0 <<= 2;
	a0 = _1d3200[d0];
	d0.w = 1;
	d0 <<= 13;
	d0.w &= 0x6000;
	d0.w += 0x0380;
	_035bf2(d0, a0);
}

void _03a426_CRAM_VSRAM_clear() {
	_03a46a();
	*VDP_CTRL = 0xc0000000; // CRAM write, address 0
	d1 = 63;
	do {
		*VDP_DATA = 0;
	} while (d1--);
	*VDP_CTRL = 0x40000010; // VSRAM write, address 0
	d1 = 39;
	do {
		*VDP_DATA.w = 0;
	} while (d1--);
	_0011fc();

}

void _03a46a() {
	*_ff2000.w = {
		4, 0x14, 0x30, 0x28, 0x7, 0x7e, 0, 0,
		0, 0, 0, 0, 0x81, 0x3c, 0, 2,
		1, 0, 0
	}
	_035604();
}

void _03a50a_VRAM_Clear_a000_bfff() { // clear VRAM 0xe000 through 0xffff
	sr |= 0x700; // I2 + I1 + I0: disable ints
	*VDP_CTRL.w = *_ff0412 | 0x10;
	*VDP_CTRL.w = 0x8f01; // Register F: autoincrement of 1
	*VDP_CTRL = 0x93ff941f; // DMA Length: 0x1fff
	*VDP_CTRL.w = 0x9780; // DMA Source: VRAM fill
	*VDP_CTRL = 0x40000083; // VRAM write, address 0xa000
	*VDP_DATA.w = 0;
	while (VDP_STATUS&1);
	*VDP_CTRL.w = 0x8f02; // Register F: autoincrement of 2
	*VDP_CTRL.w = *_ff0412;
	sr &= 0xf8ff; // reenable ints
}

void _03a554_VRAM_Clear_c000_efff() { // clear VRAM 0xe000 through 0xffff
	sr |= 0x700; // I2 + I1 + I0: disable ints?
	*VDP_CTRL.w = *_ff0412 | 0x10;
	*VDP_CTRL.w = 0x8f01; // Register F: autoincrement of 1
	*VDP_CTRL = 0x93ff941f; // DMA Length: 0x1fff
	*VDP_CTRL.w = 0x9780; // DMA Source: VRAM fill
	*VDP_CTRL = 0x60000083; // VRAM write, address 0xc000
	*VDP_DATA.w = 0;
	while (VDP_STATUS&1);
	*VDP_CTRL.w = 0x8f02; // Register F: autoincrement of 2
	*VDP_CTRL.w = *_ff0412;
	sr &= 0xf8ff; // reenable ints
}


void _03a59e_VRAM_Clear_e000_ffff() { // clear VRAM 0xe000 through 0xffff
	sr |= 0x700; // I2 + I1 + I0: disable ints?
	*VDP_CTRL.w = *_ff0412 | 0x10;
	*VDP_CTRL.w = 0x8f01; // Register F: autoincrement of 1
	*VDP_CTRL = 0x93ff941f; // DMA Length: 0x1fff
	*VDP_CTRL.w = 0x9780; // DMA Source: VRAM fill
	*VDP_CTRL = 0x70000083; // VRAM write, address 0xd000
	*VDP_DATA.w = 0;
	while (VDP_STATUS&1);
	*VDP_CTRL.w = 0x8f02; // Register F: autoincrement of 2
	*VDP_CTRL.w = *_ff0412;
	sr &= 0xf8ff; // reenable ints
}

uint16_t _03a5e8[];

void _03a654() {
	*_ff0100 |= 0x80;
	if(*_ff0100) {
		_038c38();
	} else {
		_038c0c();
	}
}

void _03a670() {
	d0.b = *_a10001;
	if ((d0 & 0x80) && !(d0 & 0x40)) {
		sr = 0x2700;
		_00119a();
		_0015b6();
		_00167a();
		nop();
		nop();
		nop();
		*VDP_CTRL = 0x8134; // Register 1: VINT, DMA, NTSC, SMS display
		*VDP_CTRL = 0xc0000000; // set vram address pointer to 0
		a0 = _03a898;
		fp = VDP_DATA;
		d5 = 15;
		do {
			*fp = *a0;
			fp += 4; a0 += 4;
		} while (d5--);
		nop();
		_00af8c();
		a0 = _03a73a;
		_03a6fa(a0);
		*VDP_CTRL = 0x811c; // Register 1: DMA, NTSC, MD mode
		sr = 0x8192;
		while(true) {nop(); nop();}
	}
}
void _03a6fa(a0) { // writes VDP
	nop();
	nop();
	nop();
	d0 = *(a0); a0+=4;
	d7.w = *(a0); a0+=2;
	d6.w = *(a0); a0+=2;
	d5.w = *(a0); a0+=2;
	do {
		*VDP_CTRL = d0;
		d4.w = d6;
		do {
			d1 = 0;
			d1.b = *(a0++);
			d1.w -= 32;
			if(d1) {
				d1.w += 9;
			}
			d1.w += d7;
			VDP_DATA.w = d1;		
		} while (d4--);
		d0 += 0x1000000;		
	} while(d5--);
}

/* end of code */

