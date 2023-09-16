#include "main.h"
int rot13(char *s)
{
    int i = 0;
    char *normal, *rot13;

    normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    while (s[i] != '\0')
    {
        int j = 0;
        while (normal[j] != '\0')
        {
            if (s[i] == normal[j])
            {
                _putchar(rot13[j]);
                break;
            }
            j++;
        }

        if (normal[j] == '\0')
        {
            _putchar(s[i]);
        }
        i++;
    }

    return i;
}

int print_rot(va_list list)
{
    char *p;
    int p_len;

    p = va_arg(list, char *);
    p_len = rot13((p != NULL) ? p : "(ahyy)");

    return p_len;
}

