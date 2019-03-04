#ifndef RESET_H_INCLUDED
#define RESET_H_INCLUDED

extern void __reset_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* RESET_H_INCLUDED */