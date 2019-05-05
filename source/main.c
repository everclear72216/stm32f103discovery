#include <ucapi/init.h>

#include "init.h"

int main(void)
{
    ucapi_init();

    init();

    for (;;) {
        asm ("nop");
    }
    
    return 0;
}
