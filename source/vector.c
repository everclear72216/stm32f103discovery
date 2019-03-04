
#include "exceptions.h"
#include "nmi.h"
#include "reset.h"

extern void __stack(void);

__attribute__ ((section (".__vector_table_flash"))) void (*const vector[16]) (void) = {
    __stack,
    __reset_isr,
    __nmi_isr,
    __hardfault_isr,
    __memmanage_isr,
    __busfault_isr,
    __usagefault_isr,
};