#include "main.h"
int handler(const char *str, va_list list)
{
    int size = 0;
    int i = 0;  // Initialize i here

    while (str[i] != '\0')  // Change to a while loop
    {
        if (str[i] == '%')
        {
            int aux = percent_handler(str, list, &i);
            if (aux == -1)
                return (-1);

            size += aux;
        }
        else
        {
            _putchar(str[i]);
            size++;
        }

        i++;  // Increment i here
    }

    return (size);
}
int percent_handler(const char *str, va_list list, int *i)
{
    int size = 0;
    int j, number_formats;
    format formats[] = {
        {'s', print_string}, {'c', print_char},
        {'d', print_integer}, {'i', print_integer},
        {'b', print_binary}, {'u', print_unsigned},
        {'o', print_octal}, {'x', print_hexadecimal_low},
        {'X', print_hexadecimal_upp}, {'p', print_pointer},
        {'r', print_rev_string}, {'R', print_rot}
    };

    (*i)++;  // Increment i through pointer

    if (str[*i] == '\0')
        return (-1);

    if (str[*i] == '%')
    {
        _putchar('%');
        return (1);
    }

    number_formats = sizeof(formats) / sizeof(formats[0]);
    for (j = 0; j < number_formats; j++)
    {
        if (str[*i] == formats[j].type)
        {
            size = formats[j].f(list);
            return (size);
        }
    }

    _putchar('%');
    _putchar(str[*i]);
    return (2);
}
