#include <limits.h>

#include "init.h"
#include "init_decl.h"
#include "init_config.h"


extern const struct init __init_table_end;
extern const struct init __init_table_start;

#define INIT_END() ((const unsigned char*)&__init_table_end)
#define INIT_START() ((const unsigned char*)&__init_table_start)
#define INIT_COUNT() ((unsigned int)(INIT_END() - INIT_START()) / sizeof(struct init))
#define INIT_BITBYTES() ((INIT_COUNT() % CHAR_BIT) ? ((INIT_COUNT() / CHAR_BIT) + 1) : (INIT_COUNT() / CHAR_BIT))

#define INIT_AT_INDEX(idx) (&((const struct init*)&__init_table_start)[(idx)])
#define INIT_TO_ADDRESS(init) ((const unsigned char*)(init))
#define INIT_TO_INDEX(init) (((unsigned int)(INIT_TO_ADDRESS(init))) / sizeof(struct init))

#define INIT_BIT(idx) (1 << ((idx) % CHAR_BIT))
#define INIT_BYTE(field, idx) ((field)[(idx) / CHAR_BIT])
#define INIT_CHECK(field, idx) (INIT_BYTE(field, index) & INIT_BIT(index))


#define DEPENDENCIES_OK         1
#define DEPENDENCIES_MISSING    2

static int check_deps(const unsigned char* done, const struct init* init)
{
    unsigned int index;

    for (index = 0; index < init->depcount; index += 1) {
        if (!INIT_CHECK(done, INIT_TO_INDEX(&init->deps[index]))) {
            return DEPENDENCIES_MISSING;
        }
    }

    return DEPENDENCIES_OK;
}

#define NEWLY_INITIALIZED       1
#define ALREADY_INITIALIZED     2
#define STILL_UNINITIALIZED     3

static int check_and_init(unsigned char* done, unsigned int index)
{
    int result;
    const struct init* current;

    if (!INIT_CHECK(done, index)) {
        current = INIT_AT_INDEX(index);

        if (DEPENDENCIES_OK == check_deps(done, current)) {
            current->init();
            result = NEWLY_INITIALIZED;
        }
        else {
            result = STILL_UNINITIALIZED;
        }
    }
    else {
        result = ALREADY_INITIALIZED;
    }

    return result;
}

#define CAUGHT_IN_LOOP          1
#define INITIALIZING            2
#define DONE                    3

static int single_pass(unsigned char* done)
{
    int result;
    unsigned int index;

    index = 0;
    result = DONE;

    for (; index < INIT_COUNT(); index += 1) {
        switch (check_and_init(done, index)) {
            case NEWLY_INITIALIZED:
                result = INITIALIZING;
                break;

            case STILL_UNINITIALIZED:
                if(INITIALIZING != result) {
                    result = CAUGHT_IN_LOOP;
                }
                break;

            case ALREADY_INITIALIZED:
            default:
                break;
        }
    }

    return result;
}

extern void init(void)
{  
    int status;
    unsigned char done[INIT_BITBYTES()];

    status = INITIALIZING;

    while(DONE != status) {
        status = single_pass(done);

        if (CAUGHT_IN_LOOP == status) {
            FATALERROR();
        }
    }
}

