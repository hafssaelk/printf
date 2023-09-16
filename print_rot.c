#include "main.h"

int print_rot(va_list list)
{
    int i = 0;
    char *normal, *rot13, *var;

    normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    var = va_arg(list, char *);
    while (var[i] != '\0')
    {
        int j = 0;
        while (normal[j] != '\0')
        {
            if (var[i] == normal[j])
            {
                _putchar(rot13[j]);
                break;
            }
            j++;
        }

        if (normal[j] == '\0')
        {
            _putchar(var[i]);
        }
        i++;
    }

    return i;
}
