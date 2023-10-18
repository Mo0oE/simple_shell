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

/**
 * rm_comment - A Function To Handle Comments in String
 * @str: The String To Handle Its Comments
 */

void rm_comment(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#' && i != 0 && str[i - 1] == ' ')
		{
			str[i] = '\0';
			break;
		}
	}
}
