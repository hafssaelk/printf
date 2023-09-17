#include "main.h"
#include <stdio.h>
/**
 * print_pointer - prints an hexadecimal number.
 * @list: arguments.
 * Return: counter.
 */
int print_pointer(va_list list)
{
	char *var;
	int count = 0, i;
	char *str;

	var = va_arg(list, unsigned long int);

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
		count += print_hexadecimal_low(var);
	}
	return (count);
}
