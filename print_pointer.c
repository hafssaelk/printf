#include "main.h"
#include <stdio.h>

int print_pointer(va_list list)
{
    char *p_buff;
    int size = 0;

    p_buff = itoa(va_arg(list, unsigned long int), 16);

    if (p_buff == NULL)
        return (-1);

    if (_strcmp(p_buff, "0") == 0)
    {
        size += print("(nil)");
    }
    else
    {
        size += print("0x");
        size += print(p_buff);
    }

    return (size);
}

int _strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }

    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else if (s1[i] != '\0')
        return s1[i];
    else
        return -s2[i];
}
