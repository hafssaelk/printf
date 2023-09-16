#include "main.h"
/**
 * get_precision - Parses the format string to calculate the precision for printing.
 * @format: The format string in which to search for precision.
 * @i: Pointer to the current position in the format string.
 * @list: The list of arguments to be printed.
 *
 * Return: The calculated precision, or -1 if no precision is specified.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    // Check if the current character is the precision specifier (dot '.').
    if (format[curr_i] != '.')
        return precision;

    precision = 0;

    // Iterate through characters in the format string to extract the precision.
    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        // If the character is a digit, update the precision.
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        // If the character is '*', get the precision from the argument list.
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        // If the character is not a valid precision specifier, exit the loop.
        else
        {
            break;
        }
    }

    // Update the position in the format string.
    *i = curr_i - 1;

    return precision;
}
