#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct _format
{
	char datatype;
	int (*f)(va_list);
} format;

int _printf(const char *, ...);
int _putchar(char);


int print_string(va_list);
int print_char(va_list);

int handler(const char *, va_list);

#endif /* MAIN_H */