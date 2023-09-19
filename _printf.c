#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int main() {
    int num = 42;
    char ch = 'A';
    char str[] = "Hello, World!";

    int result = _printf("This is a number: %d\nThis is a character: %c\nThis is a string: %s\n", num, ch, str);

    printf("\nTotal characters printed: %d\n", result);

    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0;
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    if (s != NULL) {
                        while (*s != '\0') {
                            putchar(*s);
                            s++;
                            count++;
                        }
                    } else {
                        // Handle the case when s is NULL (optional).
                        // You can decide how to handle this case based on your requirements.
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }
    
    va_end(args);
    return count;
}

