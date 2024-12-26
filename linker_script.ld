ENTRY(Reset_Handler)

MEMORY 
{
  FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 256K
  RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    /* The startup code into "FLASH" Rom type memory */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH

    /* The program code and other data into "FLASH" Rom type memory */
    .text :
    {
        . = ALIGN(4);
        _stext = .;
        *(.text*) 
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    /* Constant data into "FLASH" Rom type memory */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata*) 
        . = ALIGN(4);
        _erodata = .;
    } > FLASH

    /* Initialized data sections into "RAM" Ram type memory */
    _stored_data = .;
    .data : AT(_stored_data)
    {
        . = ALIGN(4);
        _sdata = .; /* create a global symbol at data start*/
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM

    /* Uninitialized data section into "RAM" Ram type memory */
    .bss (NOLOAD):
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;  
    } > RAM
}