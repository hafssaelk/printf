#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);
int print_hexadecimal_upp(va_list list)


{
    char *p_buff;
    int size = 0;
    int i = 0;

    p_buff = itoa(va_arg(list, unsigned int), 16);
    p_buff = string_to_upper(p_buff);

    if (p_buff != NULL)
    {
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
