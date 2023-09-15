#include "main.h"

/*
 * print_string : prints a string
 * @list: va_list.
 *
 * returns string length
 */

int print_string(va_list list)
{
	char* var;
	int count = 0, i;

	var = va_arg(list, char*);
	for (i = 0; var[i] != '\0'; ++i)
	{
		_putchar(var[i]);
		count ++;
	}
	return (count);
}