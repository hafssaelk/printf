#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            count++;
        } else {
            format++; // Move past '%'

            // Handle valid conversion specifiers: 'c', 's', and '%'
            if (*format == 'c') {
                char c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                const char *str = va_arg(args, const char *);
                while (*str) {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
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

    int printed_chars = _printf("Hello, %s! The answer is %d%%.\n", "world", num);
    printf("\nTotal characters printed: %d\n", printed_chars);

    printed_chars = _printf("A single character: %c\n", ch);
    printf("\nTotal characters printed: %d\n", printed_chars);

    return 0;
}

