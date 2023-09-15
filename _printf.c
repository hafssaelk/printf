#include "main.h"
#include <string.h>
int _printf(const char *format, ...)
{
    int size;
    va_list args;

    if (format == NULL)
        return (-1);

    size = strlen(format);
    if (size <= 0)
        return (0);

    va_start(args, format);
    size = handler(format, args);
    va_end(args);

    return (size);
}
