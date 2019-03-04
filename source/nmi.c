#include "nmi.h"

__attribute__ ((interrupt ("IRQ"))) extern void __nmi_isr(void)
{
    while(1) {}
}