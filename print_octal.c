#include "main.h"
int print_octal(va_list list, int index)
{
    char *p_buff;
    int size = 0;

    p_buff = itoa(va_arg(list, unsigned int), 8);

    if (p_buff != NULL)
    {
        int i = index;
        while (p_buff[i] != '\0')
        {
            _putchar(p_buff[i]);
            size++;
            i++;
        }
    }
    else
    {
        _putchar('N');
        _putchar('U');
        _putchar('L');
        _putchar('L');
        size += 4;
    }

    return (size);
}
