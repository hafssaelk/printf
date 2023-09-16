#include "main.h"
/**
 * get_size - Parses the format string to determine the size specifier for argument casting.
 * @format: The format string in which to search for size specifier.
 * @i: Pointer to the current position in the format string.
 *
 * Return: The size specifier constant (S_LONG, S_SHORT), or 0 if no size specifier is found.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    // Check if the current character is 'l' (long) or 'h' (short) for size specifier.
    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    // Update the position in the format string based on whether a size specifier is found.
    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return size;
}
