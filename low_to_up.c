#include "main.h"

/**
 * is_low - Check if the character are in lowercase
 * @c: Character
 * Return: 1 or 0
 **/
int is_low(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * low_to_up - Change the string to uppercase
 * @s: String
 * Return: String uppercase
 **/
char *low_to_up(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_low(s[i]))
		{
			s[i] = s[i] - 32;
		}
	}

	return (s);
}
