#include "main.h"

/**
 * print_hexadecimal_low - Print a number in base 16
 * @list: Number to print in base 16
 *
 * Return: Length of th numbers in decimal...
 **/
int print_hexadecimal_upp(va_list list)
{
	char *var, *upper_var;
	int count = 0, i;

	var = itoa(va_arg(list, unsigned int), 16);
	upper_var = low_to_up(var);

	for (i = 0; upper_var[i] != '\0'; ++i)
	{
		_putchar(upper_var[i]);
		count ++;
	}
	return (count);
}

