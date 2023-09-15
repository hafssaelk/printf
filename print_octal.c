#include "main.h"

/**
 * print_octal - Print a number in base 8
 * @list: Number to print in base 8
 *
 * Return: Length of th numbers
 **/
int print_octal(va_list list)
{
	char *var;
	int count = 0, i;

	var = itoa(va_arg(list, unsigned int), 8);

	for (i = 0; var[i] != '\0'; ++i)
	{
		_putchar(var[i]);
		count ++;
	}
	return (count);
}
