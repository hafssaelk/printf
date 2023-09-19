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

            if (*format == 'S') {
                const char *str = va_arg(args, const char *);
                while (*str) {
                    if (*str >= 32 && *str < 127) {
                        putchar(*str);
                        count++;
                    } else {
                        printf("\\x%02X", (unsigned char)*str);
                        count += 4;
                    }
                    str++;
                }
            } else {
                putchar('%'); // Print '%' and the invalid specifier as is
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
    _printf("%S\n", "Best\nSchool");

    return 0;
}

