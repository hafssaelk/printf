#include "main.h"
/**
 * printf_exclusive_string - print exclusive string.
 * @list: argument.
 * Return: the length of the string.
 */

int printf_ex_string(va_list val)
{
	char *var;
	int i, count = 0;
	int cast;

	var = va_arg(val, char *);
	if (var == NULL)
		var = "(null)";
	for (i = 0; var[i] != '\0'; i++)
	{
		if (var[i] < 32 || var[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count = count + 2;
			cast = var[i];
			if (cast < 16)
			{
				_putchar('0');
				count++;
			}
			count = count + printf_HEX_aux(cast);
		}
		else
		{
			_putchar(var[i]);
			count;
		}
	}
	return (len);
}