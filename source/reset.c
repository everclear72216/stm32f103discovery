#include "main.h"

#include "reset.h"

extern unsigned char __bss_vma;
extern const unsigned char __bss_vma_end;

extern unsigned char __data_vma;
extern const unsigned char __data_lma;
extern const unsigned char __data_vma_end;

__attribute__ ((interrupt ("IRQ"))) extern void __reset_isr(void)
{
    unsigned char* dst;
    const unsigned char* src;

    asm("nop");
    asm("nop");

    /* initialize static variables */
    dst = &__bss_vma;
    while(dst != &__bss_vma_end)
    {
        *dst++ = 0u;
    }

    /* initialize data */
    src = &__data_lma;
    dst = &__data_vma;
    while(dst != &__data_vma_end)
    {
        *dst++ = *src++;
    }

    main();

    while(~0) {}
}