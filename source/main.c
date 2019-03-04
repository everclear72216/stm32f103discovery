#include "init.h"

int main(void)
{
    init();

    for (;;) {
        asm ("nop");
    }
    
    return 0;
}
