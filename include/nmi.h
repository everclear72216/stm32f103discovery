#ifndef NMI_H_INCLUDED
#define NMI_H_INCLUDED

extern void __nmi_isr(void) __attribute__ ((interrupt ("IRQ")));

#endif /* NMI_H_INCLUDED */