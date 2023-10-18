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

/**
 * is_echo - A Function To Print
 * @input_args: the array of arrguments
 * @input_line: the original input line
 * Return: 0 if Success or 1 otherwise
 */

int is_echo(char **input_args, char *input_line)
{
	size_t pid;
	char *str = (char *)malloc(50);
	char *env_var_value, *env_var_name;

	if (_strcmp(input_args[0], "echo") == 0)
	{
		if (input_args[1] != NULL)
		{
			if (_strcmp(input_args[1], "$$") == 0)
			{
				pid = getpid();
				int_to_str(pid, str);
				_puts(str);
			}
			else if (strcmp(input_args[1], "$?") == 0)
				_puts("1\n");
			else if (input_args[1][0] == '$' && input_args[1][1] != '\0')
			{
				env_var_name = &input_args[1][1];
				env_var_value = getenv(env_var_name);
				if (env_var_value != NULL)
					_puts(env_var_value), _puts("\n");
				else
					_puts("");
			}
			else
				_puts(input_args[1]), _puts("\n");
		}
		else
			_puts("");
		free(str);
		free(input_line);
		free_my_array(input_args);
		free(input_args);
		return (0);
	}
	free(str);
	return (1);
}
