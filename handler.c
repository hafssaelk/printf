#include "main.h"

/**
* percent_handler - Controls for percent format
* @str: String format
* @list: List of arguments
* @i: Iterator
*
* Return: Size of the printed arguments
**/
int percent_handler(const char *str, va_list list, int *i)
{
	int size = 0;
	int j, number_formats;
	format formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'u', print_unsigned}, {'b', print_binary},
		{'o', print_octal}, {'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp}, {'p', print_pointer}
	};

	*i = *i + 1;  /* Increment i through pointer */
	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (j = 0; j < number_formats; j++)
		{
			if (str[*i] == formats[j].datatype)
			{
				size = formats[j].f(list);
				return (size);
			}
		}
	if (str[*i] == '\0')
	{
		_putchar('%');
		return (0);
	}

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}
	_putchar(str[*i]);
	return (2);
}

/**
* handler - Format controller
* @str: String format
* @list: List of arguments
*
* Return: Total size of arguments plus the total size of the base string...
**/
int handler(const char *str, va_list list)
{
int size = 0, var;
int i = 0;  /* Initialize i here */

while (str[i] != '\0')  /* Change to a while loop */
	{
		if (str[i] == '%')
		{
			var = percent_handler(str, list, &i);
			if (var == -1)
				return (var);

			size += var;
		}
		else
		{
			_putchar(str[i]);
			size++;
		}
		i++;  /* Increment i here */
	}
	return (size);
	}
