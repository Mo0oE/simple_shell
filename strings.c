#include "shell.h"

/**
 * _strlen - A Function To Get The Length of String
 * @str: The String
 *
 * Return: The Length of str
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - A Function To Compare Between 2 Strings
 * @str1: The First String
 * @str2: The Second String
 *
 * Return: The Difference Between The 2 Strings
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return (0);

		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
 * _strcat - A Function The Concates 2 Strings
 * @str1: The First String
 * @str2: The Second String
 * Description: A String Contains Both of Them
 */

void _strcat(char *str1, char *str2)
{
	char *end_of_str1 = str1;

	while (*end_of_str1 != '\0')
	{
		end_of_str1++;
	}

	while (*str2 != '\0')
	{
		*end_of_str1 = *str2;
		end_of_str1++;
		str2++;
	}

	*end_of_str1 = '\0';
}

/**
 * _strdup - A Function To Duplicates A String
 * @str: The String To Duplicate
 *
 * Return: The Duplicated String
 */

char *_strdup(char *str)
{
	int len;
	char *result = NULL;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	result = (char *)malloc(len + 1);

	if (result)
	{
		_strcpy(result, str);
	}

	return (result);
}

/**
 * _strcpy - A Function To Copy A String Into Another
 * @dest: The Destination String
 * @src: The Source String
 */

void _strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
