#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void
kill_program(char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    vfprintf(stderr, format, ap);
    va_end(ap);

    exit(EXIT_FAILURE);
}

void *
xcalloc(size_t n, size_t size)
{
    void *p;

    if (!n)
        kill_program("xcalloc: can't allocate 0 bytes");

    p = calloc(n, size);
    if (!p)
        kill_program("xcalloc: failed to allocate");

    return p;
}
