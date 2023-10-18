#include "shell.h"

/**
 * is_setenv - A Function To Unset Env Variable
 * @input_args: the array of arrguments
 * @input_line: the original input line
 * Return: 0 if Success or 1 otherwise
 */

int is_setenv(char **input_args, char *input_line)
{

	if (_strcmp(input_args[0], "setenv") == 0)
	{
		if (setenv(input_args[1], input_args[2], 1) == -1)
		{

			perror("setenv error");
			free_my_array(input_args);
			free(input_args);
			free(input_line);
			return (1);
		}
		else
		{
			free_my_array(input_args);
			free(input_args);
			free(input_line);
			return (0);
		}
	}
	return (1);
}

/**
 * is_unsetenv - A Function To Unset Env Variable
 * @input_args: the array of arrguments
 * @input_line: the original input line
 * Return: 0 if Success or 1 otherwise
 */

int is_unsetenv(char **input_args, char *input_line)
{
	if (_strcmp(input_args[0], "unsetenv") == 0)
	{
		if (unsetenv(input_args[1]) == -1)
		{
			perror("unsetenv error");
			free(input_line);
			free_my_array(input_args);
			free(input_args);
			return (1);
		}
		else
		{
			free(input_line);
			free_my_array(input_args);
			free(input_args);
			return (0);
		}
	}
	return (1);
}

