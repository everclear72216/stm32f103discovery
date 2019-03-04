#ifndef FATALERROR_H_INCLUDED
#define FATALERROR_H_INCLUDED

#define FATALERROR() fatalerror(__FILE__, __LINE__)

extern void fatalerror(const char* file, unsigned int line);

#endif /* FATALERROR_H_INCLUDED */