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
		if (str[i] == '#' && (i != 0 || str[i - 1] == ' '))
		{
			str[i] = '\0';
			break;
		}
	}
}

/**
 * int_to_str - A Function To Convert Number to String
 * @num: The Number To Convert
 * @str: The String Output of The Function
 */

void int_to_str(size_t num, char *str)
{
	char temp;
	int i = 0, j = 0;

	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	str[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
	str[i] = '\n';
}
