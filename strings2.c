#include "shell.h"

/**
 * _puts - function
 * @str: string
 * Description: None
*/

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}
