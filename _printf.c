#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0; // To keep track of the number of characters printed
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Unsupported format specifier, just print it as is
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            // Non-format character, just print it
            putchar(*format);
            count++;
        }
        format++; // Move to the next character in the format string
    }
    
    va_end(args);
    return count;
}

int main() {
    int num = 42;
    char ch = 'A';
    char *str = "Hello, World!";
    
    int result = _printf("This is a number: %d\nThis is a character: %c\nThis is a string: %s\n", num, ch, str);
    
    printf("\nTotal characters printed: %d\n", result);
    
    return 0;
}

