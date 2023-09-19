#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format);
            count++;
        } else {
            format++; // Move past '%'
            if (*format == 'c') {
                // Handle character argument
                char c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Handle string argument
                const char *str = va_arg(args, const char *);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                // Handle '%' character
                putchar('%');
                count++;
            } else {
                // Invalid format specifier, treat '%' followed by any other character as is
                putchar('%');
                putchar(*format);
                count += 2;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}

int main(void) {
    int num = 42;
    char ch = 'A';

    _printf("Hello, %s! The answer is %d%%.\n", "world", num);
    _printf("A single character: %c\n", ch);

    return 0;
}

