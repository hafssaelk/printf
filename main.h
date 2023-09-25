#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef struct _format
{
        char datatype;
        int (*f)(va_list);
} format;

int _printf(const char *, ...);
int _putchar(char);

char *itoa(long int, int);
char *low_to_up(char *);


int print_string(va_list);
int print_char(va_list);
int print_integer(va_list);
int print_unsigned(va_list);
int print_binary(va_list);
int print_octal(va_list);
int print_hexadecimal_upp(va_list);
int print_hexadecimal_low(va_list);
int print_pointer(va_list);
int print_rev_string(va_list);
int print_rot(va_list);

int handler(const char *, va_list);
int percent_handler(const char *str, va_list list, int *i);
int print_hexadecimal_upp2(int s);

#endif /* MAIN_H */
