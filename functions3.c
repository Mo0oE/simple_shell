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
 *
 * Return: A String Contains Both of Them
 */

char *_strcat(char *str1, char *str2)
{
	char *result = NULL;
	int i, len1 = 0, len2 = 0;

	while (str1[len1] != '\0')
		len1++;

	while (str2[len2] != '\0')
		len2++;

	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = str1[i];

	for (i = 0; i < len2; i++)
		result[len1 + i] = str2[i];

	result[len1 + len2] = '\0';
	return (result);
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

