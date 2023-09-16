#include "main.h"
int print_rev_string(va_list list)
{
    int i, size;
    const char *str;

    str = va_arg(list, const char *);

    size = _strlen(str);

    for (i = size; i > 0; i--)
        _putchar(str[i - 1]);

    return (size);
}
