#ifndef INIT_DECL_H_INCLUDED
#define INIT_DECL_H_INCLUDED

struct init
{
    struct init* deps;
    unsigned int depcount;
    void (*init)(void);
};

#define DECLARE_INITIALIZER(name, func, ...) \
__attribute__((section (.dependencies))) static const struct init __deps[] = { \
    __VA_ARGS__ \
}; \
 \
__attribute__((section (.initializers))) extern const struct init __init_ ## name = { \
    __deps, \
    sizeof(__deps) / sizeof(*__deps), \
    func \
};

#endif /* INIT_DECL_H_INCLUDED */
