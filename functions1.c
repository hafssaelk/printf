#include "main.h"
/************************* Function: Unsigned Number Printer *************************/
/**
 * print_unsigned - Handles the printing of an unsigned number.
 * @types: List of arguments
 * @buffer: A character buffer used for output
 * @flags: Flag settings used in calculations
 * @width: The specified width for formatting
 * @precision: The precision specification
 * @size: The size specifier
 *
 * This function takes a list of arguments, extracts an unsigned number, and prints
 * it based on the provided formatting options.
 *
 * Returns: The number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************* Function: Octal Unsigned Number Printer  ****************/
/**
 * print_octal - Handles the printing of an unsigned number in octal notation.
 * @types: List of arguments
 * @buffer: A character buffer used for output
 * @flags: Flag settings used in calculations
 * @width: The specified width for formatting
 * @precision: The precision specification
 * @size: The size specifier
 *
 * This function takes a list of arguments, extracts an unsigned number, and prints
 * it in octal notation based on the provided formatting options.
 *
 * Returns: The number of characters printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************** Function: Hexadecimal Unsigned Number Printer (Lowercase) **************/
/**
 * print_hexadecimal_lower - Handles the printing of an unsigned number in hexadecimal notation.
 * @types: A list of arguments
 * @buffer: A character buffer used for output
 * @flags: Flag settings used in calculations
 * @width: The specified width for formatting
 * @precision: The precision specification
 * @size: The size specifier
 *
 * This function takes a list of arguments, extracts an unsigned number, and prints
 * it in lowercase hexadecimal notation based on the provided formatting options.
 *
 * Returns: The number of characters printed.
 */
int print_hexadecimal_lower(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* Function: Hexadecimal Unsigned Number Printer (Uppercase) **************/
/**
 * print_hexadecimal_upper - Handles the printing of an unsigned number in uppercase hexadecimal notation.
 * @types: A list of arguments
 * @buffer: A character buffer used for output
 * @flags: Flag settings used in calculations
 * @width: The specified width for formatting
 * @precision: The precision specification
 * @size: The size specifier
 *
 * This function takes a list of arguments, extracts an unsigned number, and prints
 * it in uppercase hexadecimal notation based on the provided formatting options.
 *
 * Returns: The number of characters printed.
 */
int print_hexadecimal_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/************** Function: Hexadecimal Number Printer (Lower/Upper) **************/
/**
 * print_hexadecimal - Handles the printing of a hexadecimal number in either lowercase or uppercase.
 * @types: A list of arguments
 * @map_to: An array of values to map the number to
 * @buffer: A character buffer used for output
 * @flags: Flag settings used in calculations
 * @flag_ch: The character used for flag calculations
 * @width: The specified width for formatting
 * @precision: The precision specification
 * @size: The size specifier
 *
 * This function takes a list of arguments, extracts an unsigned number, and prints
 * it in hexadecimal notation (either lowercase or uppercase) based on the provided
 * formatting options.
 *
 * Returns: The number of characters printed.
 */
int print_hexadecimal(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
