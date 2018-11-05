/* Flash layout for 1MB+ chips */

MEMORY
{
  dport0_0_seg : org = 0x3ff00000, len = 0x10
  dram0_0_seg :  org = 0x3ffe8000, len = 0x14000
  iram1_0_seg :  org = 0x40100000, len = 0x8000
  irom0_0_seg :  org = 0x40200080, len = 0xff000
}

PROVIDE ( _SPIFFS_end = 0x402FB000 );

INCLUDE "eagle.app.v6.common.ld"
