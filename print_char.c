#include "main.h"

/*
 * print_char : prints a single character
 * @list: va_list.
 *
 * returns : 1
 */

int print_char(va_list list)
{
	int var;

	var = va_arg(list, int);
	_putchar(var);
	return (1);
}
