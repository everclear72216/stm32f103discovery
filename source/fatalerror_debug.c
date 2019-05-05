#include "ucapi/debug.h"
#include "ucapi/breakpoint.h"

#include "fatalerror.h"

extern void fatalerror(const char* file, unsigned int line)
{
    if (ucapi_debug_enabled == ucapi_get_debug_state()) {
        ucapi_breakpoint();
    }
    else {
        for(;;) {}
    }
}
