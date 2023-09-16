#include "main.h"

/**
 * print_hexadecimal_low - Print a number in base 16
 * @list: Number to print in base 16
 *
 * Return: Length of th numbers in decimal...
 **/
int print_hexadecimal_low(va_list list)
{
	char *var;
	int count = 0, i;

	var = itoa(va_arg(list, unsigned int), 16);

	for (i = 0; var[i] != '\0'; ++i)
	{
		_putchar(var[i]);
		count ++;
	}
	return (count);
}

