#include <stdio.h>
#include <stdarg.h>

void custom_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'
            if (*format == 'S') {
                format++; // Move past 'S'
                const char* str = va_arg(args, const char*);

                while (*str) {
                    if (*str >= 32 && *str < 127) {
                        putchar(*str);
                    } else {
                        printf("\\x%02X", *str);
                    }
                    str++;
                }
            } else if (*format == '%') {
                putchar('%'); // Print '%' when '%%' is encountered
                format++;
            } else {
                putchar('%'); // Print '%' if the specifier is not recognized
            }
        } else {
            putchar(*format); // Print normal characters
        }
        format++;
    }

    va_end(args);
}

int main() {
    const char* text = "Hello, \x01\x02\x03 World!";
    custom_printf("Custom format: %S\n", text);
    return 0;
}
