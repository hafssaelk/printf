#include "main.h"
/**
 * print_exclusive_string - print exclusive string.
 * @val: argument.
 * Return: the length of the string.
 */

int print_ex_string(va_list val)
{
	char *s;
	int i, len = 0;
	int cast;

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_hexadecimal_upp2(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}
