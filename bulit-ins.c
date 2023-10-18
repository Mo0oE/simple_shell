#include "shell.h"

/**
 * * is_help - a function to handel the cd command
 * @input_arg: the tokens of input command line
 * @input_line: the original line of input
 * Return: 0 if it's a help command and a 1 otherwise
 */

int is_help(char **input_arg, char *input_line)
{
	if (_strcmp(input_arg[0], "help") == 0)
	{
		_puts("This is the shell help menu.\nbulit-ins:\nenv\ncd\nhelp\nexit\n");
		free(input_line);
		free_my_array(input_arg);
		free(input_arg);
		return (0);
	}
	return (1);
}

/**
 * is_cd - a function to handel the cd command
 * @input_arg: the tokens of input command line
 * @input_line: the original line of input
 * Return: 0 if not a cd command and a 1 otherwise
 */

int is_cd(char **input_arg, char *input_line)
{
	if (_strcmp(input_arg[0], "cd") == 0)
	{
		if (input_arg[1] == NULL)
		{
			perror("No argument for cd");
			free(input_line);
			free_my_array(input_arg);
			free(input_arg);
			return (0);
		}
		else
		{
			if (chdir(input_arg[1]) != 0)
			{
				perror("chdir error");
				free(input_line);
				free_my_array(input_arg);
				free(input_arg);
				return (0);
			}
		}
		free(input_line);
		free_my_array(input_arg);
		free(input_arg);
		return (0);
	}
	return (1);
}

/**
 * is_env - the function to handle the env command
 * @input_args: the array of arrguments
 * @input_line: the original input line
 * @envp: the environment variables array
 * Return: 0 if env or 1 otherwise
*/

int is_env(char **input_args, char *input_line, char *envp[])
{
	if (_strcmp(input_args[0], "env") == 0)
	{
		int i = 0;

		while (envp[i] != NULL)
		{
			_puts(envp[i]);
			_puts("\n");
			i++;
		}
		free(input_line);
		free_my_array(input_args);
		free(input_args);
		return (0);
	}

	return (1);
}

/**
 * is_exit - the function to handle the exit command
 * @input_args: the array of arrguments
 * @input_line: the original input line
 * Return: 0 if env or 1 otherwise
*/


int is_exit(char **input_args, char *input_line)
{
	if (_strcmp(input_args[0], "exit") == 0)
	{
		free(input_line);
		free_my_array(input_args);
		free(input_args);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
