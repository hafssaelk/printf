#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char name = '.';
    _printf("Let's try to printf a simple sentence.\n");
    _printf("hello\n");
	_printf("hello my name is %c\n", name);
	return (0);
}
