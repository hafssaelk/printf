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
            switch (*format) {
                case 'c':
                    // Handle character argument
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    // Handle string argument
                    {
                        const char *str = va_arg(args, const char *);
                        while (*str != '\0') {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    // Handle '%' character
                    putchar('%');
                    count++;
                    break;
                default:
                    // Invalid format specifier
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
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
