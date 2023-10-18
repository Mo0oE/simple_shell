#include "shell.h"

/**
 * get_shell_line - function to get the input command
 * Return: The input string
 */

char *get_shell_line(void)
{
	char *input_line = NULL;
	size_t input_buffer_size = 0;

	if (getline(&input_line, &input_buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input_line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input_line);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (input_line);
}

/**
 * get_shell_args - function to divide the input string into tokens
 * @shell_line: the original input string
 * Return: an array of strings of these tokens
 */

char **get_shell_args(char *shell_line)
{
	int buffer_size = TOKENS_BUFFER;
	int i = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));

	char *tmp_token, *delim = " \t\r\n\a";

	if (!tokens)
	{
		perror("Can't malloc tokens");
		exit(EXIT_FAILURE);
	}

	tmp_token = strtok(shell_line, delim);

	while (tmp_token)
	{
		if (_strcmp(tmp_token, "") != 0)
		{
			tokens[i] = _strdup(tmp_token);
			i++;
		}
		if (i == buffer_size)
		{
			buffer_size *= 2;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				perror("Can't realloc tokens");
				exit(EXIT_FAILURE);
			}
		}
		tmp_token = strtok(NULL, delim);
	}
	if (i == 0)
	{
		free(tokens);
		return (NULL);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * shell_excute - the function that excute the given command
 * @path: the path of the program to be excuted
 * @args: the arguments to be excuted with the program
 * @envp: the environment variables
 * Description: it exexutes the given command with the given arguments
 */

void shell_excute(char *path, char **args, char *envp[])
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(path, args, envp) == -1)
		{
			if (execve(args[0], args, envp) == -1)
			{
				perror(": execve error");
			}
		}
		free_my_array(args);
		free(args);
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork error");
	}
	else
	{
		wait(NULL);
	}
}

/**
 * free_my_array - a function to free an array of strings
 * @args: the array to be freed
 * Description: frees every string in the array not including the array itself
 */

void free_my_array(char **args)
{
	while (*args != NULL)
	{
		free(*args);
		args++;
	}
}
