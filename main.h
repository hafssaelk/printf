#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

// FLAGS
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

// SIZES
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct print_format - Structure to hold format specifier and its function.
 * @specifier: Format specifier character.
 * @function: Corresponding print function.
 */
struct print_format
{
    char specifier;
    int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct print_format print_format_t - Typedef for struct print_format.
 */
typedef struct print_format print_format_t;

/**
 * _printf - Custom printf function.
 */
int _printf(const char *format, ...);

/**
 * handle_print - Handle print based on format specifier.
 */
int handle_print(const char *format, int *i,
                 va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_ch(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_perc(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_unsigned_num(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_hexa_dec(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable_chars(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Function to print memory address */
int print_memory_address(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print string in reverse */
int print_reversed_string(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int print_rot13_encoded_string(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Width handler functions and others */
int handle_write_character(char c, char buffer[],
    int flags, int width, int precision, int size);
int write_integer_number(int is_positive, int ind, char buffer[],
    int flags, int width, int precision, int size);
int write_number(int ind, char bff[], int flags, int width, int precision,
    int length, char padd, char extra_c);
int write_memory_address(char buffer[], int ind, int length,
    int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned_num(int is_negative, int ind,
char buffer[],
    int flags, int width, int precision, int size);

/****************** UTILITIES ******************/
int is_printable_char(char);
int append_hexadecimal_code(char, char[], int);
int is_numeric_digit(char);

long int convert_number_with_size(long int num, int size);
long int convert_unsigned_number_with_size(unsigned long int num, int size);
#endif /* MAIN_H */
