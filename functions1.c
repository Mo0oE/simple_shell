#include "shell.h"

/**
 * get_shell_line - function to get the input command
 * Return: The input string
 */

char *get_shell_line(void)
{
	char input[MAX_INPUT_LENGTH];
	char *input_line;
	ssize_t bytes_read = read(STDIN_FILENO, input, sizeof(input));

	if (bytes_read == -1)
	{
		perror("Error: Failed to read input");
		exit(EXIT_FAILURE);
	}

	input[bytes_read - 1] = '\0';

	input_line = strdup(input);
	if (input_line == NULL)
	{
		perror("Error: Failed to allocate memory");
		exit(EXIT_FAILURE);
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
		if (strcmp(tmp_token, "") != 0)
		{
			tokens[i] = strdup(tmp_token);
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
 * is_cd - a function to handel the cd command
 * @input_arg: the tokens of input command line
 * @input_line: the original line of input
 * Return: 0 if not a cd command and a 1 otherwise
 */

int is_cd(char **input_arg, char *input_line)
{
	if (strcmp(input_arg[0], "cd") == 0)
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