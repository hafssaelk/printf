#include "main.h"

/**
 * print_binary - Print a number in base 2
 * @list: Number to print in base 2
 *
 * Return: Length of the numbers
 **/
int print_binary(va_list list)
{
	char *var;
	int count = 0, i;

	var = itoa(va_arg(list, unsigned int), 2);

	for (i = 0; var[i] != '\0'; ++i)
	{
		_putchar(var[i]);
		count ++;
	}
	return (count);
}

