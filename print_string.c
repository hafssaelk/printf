#include "main.h"

/*
 * print_string : prints a string
 * @list: va_list.
 *
 * returns string length
 */

int print_string(va_list list)
{
	int var, count = 1;

	var = va_arg(list, int);
	while (var != 0)
	{
		_putchar(var);
		var = va_arg(list, int);
		count++;
	}
	return (count);
}