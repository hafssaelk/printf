#include "main.h"
/**
 * get_width - Parses the format string to determine the width for formatting.
 * @format: The format string in which to search for the width specifier.
 * @i: Pointer to the current position in the format string.
 * @list: The va_list containing the variable arguments.
 *
 * Return: The width specifier value, or 0 if no width specifier is found.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i;
    int width = 0;

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        // Check if the current character is a digit (0-9) to accumulate width.
        if (is_digit(format[curr_i]))
        {
            width *= 10;
            width += format[curr_i] - '0';
        }
        // Check if the current character is '*' to fetch width from variable arguments.
        else if (format[curr_i] == '*')
        {
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    // Update the position in the format string based on whether a width specifier is found.
    *i = curr_i - 1;

    return width;
}
