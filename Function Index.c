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
void _0006c2();
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

void _0015a0();

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
void _001e76();
void _001f40();
void _001fb6();
void _001fc2();
void _001fcc();
void _001fdc();

uint16_t _001ff0[16];

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
void _005716();
void _0057b8();
void _0057f0();

void _005aa6();

void _005c22();
void _005c54();
void _005c88();

void _005d18(); // updates VDP
void _005d64(); // updates VDP