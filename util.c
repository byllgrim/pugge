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
