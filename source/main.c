#include <ucapi/clock.h>

#include "init.h"

int main(void)
{
    ucapi_clock_init();

    init();

    for (;;) {
        asm ("nop");
    }
    
    return 0;
}
