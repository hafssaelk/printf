#include "main.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int len = 0, len2 = 0;

	len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
		len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	return 0;
}