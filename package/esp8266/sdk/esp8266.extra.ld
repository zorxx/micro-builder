SECTIONS
{
  .irom0.other : ALIGN(4) SUBALIGN(4)
  {
    _irom0_other_start = ABSOLUTE(.);
    *.bin.o(*)
    . = ALIGN (4);
    _irom0_other_end = ABSOLUTE(.);
  } >irom0_0_seg :irom0_0_phdr
}
