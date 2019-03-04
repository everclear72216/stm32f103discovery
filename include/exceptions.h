#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

extern void __busfault_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __hardfault_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __memmanage_isr(void) __attribute__ ((interrupt ("IRQ")));

extern void __usagefault_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* EXCEPTIONS_H_INCLUDED */