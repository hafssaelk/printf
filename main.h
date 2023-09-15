#ifndef MAIN_H
#define MAIN_H

typedef struct _format
{
	char datatype;
	int (*f)(va_list);
} format;

int _printf(const char *, ...);
int _putchar(char);

#endif /* MAIN_H */