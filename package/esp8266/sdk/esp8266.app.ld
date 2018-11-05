MEMORY
{
  dport0_0_seg : org = 0x3FF00000, len = 0x10
  /* All .data/.bss/heap are in this segment. 1024 bytes is for system start and interrupt*/
  dram0_0_seg : org = 0x3FFE8000, len = 0x18000 - 1024
  /* Functions which are critical should be put in this segment. */
  iram1_0_seg : org = 0x40100000, len = 0x8000
  /* It is actually mapped to flash. */
  irom0_0_seg : org = 0x40200080, len = 0xfff000
  /* RTC memory, persists over deep sleep. */
  rtc_seg : org = 0x60001200, len = 0x200
}
