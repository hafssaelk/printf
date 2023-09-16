#include "main.h"
#include <stdio.h>

int print_pointer(va_list list)
{
    char *var;
    int count = 0, i;
    char *str;

    var = itoa(va_arg(list, unsigned long int), 16);

    if (var == NULL)
        return (-1);

    if (strcmp(var, "0") == 0)
    {
        str = "(nil)";
        for (i = 0; str[i] != '\0'; ++i)
		{
            _putchar(str[i]);
            count++;
        }
        return (count);
    }
    else
    {
        str = "0x";
        for (i = 0; str[i] != '\0'; ++i)
		{
            _putchar(str[i]);
            count++;
        }
        for (i = 0; var[i] != '\0'; ++i)
		{
            _putchar(var[i]);
            count++;
        }
    }

     return (count);
}
