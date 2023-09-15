#include "main.h"
/**
 * print_unsigned - Print an unsigned number in base 10
 * @list: Number to print in base 10
 *
 * Return: Length of th numbers in decimal...
 **/
int print_unsigned(va_list list)
{
	char *var;
	int count = 0, i;

	var = itoa(va_arg(list, unsigned int), 10);

	for (i = 0; var[i] != '\0'; ++i)
	{
		_putchar(var[i]);
		count ++;
	}
	return (count);
}
