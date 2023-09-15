#include "main.h"

/**
 * print_integer - Print a number in base 10
 * @list: Number to print in base 10
 *
 * Return: Length of th numbers in decimal...
 **/
int print_integer(va_list list)
{
	char *var;
	int count = 0, i;

	var = itoa(va_arg(list, int), 10);

	for (i = 0; var[i] != '\0'; ++i)
	{
		_putchar(var[i]);
		count ++;
	}
	return (count);
}
