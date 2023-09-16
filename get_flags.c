#include "main.h
/**
 * get_flags - Parses the format string to calculate active format flags.
 * @format: The format string in which to identify format flags.
 * @i: Pointer to the current position in the format string.
 * Return: The calculated format flags.
 */
int get_flags(const char *format, int *i)
{
    // Define characters representing format flags and their corresponding values.
    const char FLAGS_CHARACTERS[] = "-+0# ";
    const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

    int flags = 0;
    int curr_i = *i + 1;

    // Iterate through characters in the format string.
    while (format[curr_i] != '\0')
    {
        char curr_char = format[curr_i];
        int flag_index;

        // Check if the current character is a format flag character.
        for (flag_index = 0; FLAGS_CHARACTERS[flag_index] != '\0'; flag_index++)
        {
            if (curr_char == FLAGS_CHARACTERS[flag_index])
            {
                flags |= FLAGS_VALUES[flag_index]; // Set the corresponding flag.
                break;
            }
        }

        // If the character is not a valid format flag, exit the loop.
        if (FLAGS_CHARACTERS[flag_index] == '\0')
        {
            break;
        }

        curr_i++;
    }

    // Update the position in the format string.
    *i = curr_i - 1;

    return flags;
}
