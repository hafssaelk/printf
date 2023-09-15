#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);


int handler(const char *format, va_list args)
{
    int count = 0;  

    while (*format)
    {
        if (*format == '%')
        {
            format++;  
            switch (*format)
            {
                case 'c':
                    
                    _putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    
                    {
                        const char *str = va_arg(args, const char *);
                        while (*str)
                        {
                            _putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    
                    _putchar('%');
                    count++;
                    break;
                default:
                    
                    break;
            }
        }
        else
        {
            
            _putchar(*format);
            count++;
        }
        format++;  
    }

    return count;
}

