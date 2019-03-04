ENTRY(__reset_isr)

SECTIONS
{
    .text :
    {
        PROVIDE(__vector_table_flash_start = .);
        KEEP(*(.__vector_table_flash))
        . = ALIGN(4);
        PROVIDE(__vector_table_flash_end = .);

        . = ALIGN(4);
        PROVIDE(__init_table_start = .);
        *(.initializers*)
        PROVIDE(__init_table_end = .);

        *(.dependencies*);
        *(.text*)
        *(.rodata*)
    } >FLASH

    . = ORIGIN(SRAM);
    .ram.vectortable :
    {
        PROVIDE(__vector_table_ram_start = .);
        KEEP(*(.vector_table_ram))
        . = ALIGN(4);
        PROVIDE(__vector_table_ram_end = .);

        *(.text*)
    } >SRAM

    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        . = ALIGN(4);
        PROVIDE(__data_lma = LOADADDR(.data));
        PROVIDE(__data_vma = .);
        *(.data*)
        PROVIDE(__data_vma_end = .);
    } >SRAM

    .bss :
    {
        . = ALIGN(4);
        PROVIDE(__bss_vma = .);
        *(.bss*)
        PROVIDE(__bss_vma_end = .);
    } >SRAM

    .stack :
    {
        *(.stack*)
    } >SRAM

    __stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
    __stack_bot = __stack_top - SIZEOF(.stack);
    PROVIDE(__stack = __stack_top);
}