// Hybrid front memory regions

uint32_t _ff0100; // read in 00075e
uint16_t _ff0104; // write/test in 0006c2, write in 0006d6

uint16_t _ff010e; // read in 0006c2

uint8_t _ff011e; // test in 00075e

uint8_t _ff0184; // bit 0 clear in 00077e
uint32_t _fff0186; // add 1 in 0007f6

uint16_t _ff0410[19]; // fill in 0015f2
uint8_t _ff0413; // write in 00077e, write in 0007f6


uint16_t _ff043a; // write in 0015b3 and 0015f2
uint16_t _ff043c; // write in 0015b3 and 0015f2
uint16_t _ff043e; // write in 0015b3 and 0015f2
uint16_t _ff0440; // write in 0015b3 and 0015f2
uint16_t _ff0442; // write in 0015b3 and 0015f2

uint32_t _ff2000[2048]; // cleared at 003466
uint32_t _ff4000[1024]; // cleared at 00343e
uint32_t _ff6000[1024]; // cleared at 003452

void _ff9000();
void _ff9030();
void _ff9060();

uint32_t _ffe000[32];

uint32_t _fff300[16]; // compare in 00077e
uint32_t _fff380[16]; // compare in 00077e

// stack is below this... whatever
uint32_t _ffff00[192];