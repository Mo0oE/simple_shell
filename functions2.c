#include "shell.h"

/**
 * interactive_shell - controll the shell in the non interactive mode
 * @envp: the evironment array
 * Description: handle the shell
*/

void interactive_shell(char **envp)
{
	char *input_line, *prog_path;
	char **input_args;
	int shell_status = 1;

	while (shell_status)
	{
		write(STDOUT_FILENO, "myprompt$ ", 10);
		input_line = get_shell_line();
		input_args = get_shell_args(input_line);
		if (!input_args)
		{
			free(input_line);
			continue;
		}
		if (!is_exit(input_args, input_line))
			exit(EXIT_SUCCESS);
		if (!is_cd(input_args, input_line))
			continue;
		if (!is_env(input_args, input_line, envp))
			continue;
		prog_path = malloc(strlen(input_args[0]) + strlen("/bin/") + 1);
		if (prog_path == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}
		strcpy(prog_path, "/bin/");
		strcat(prog_path, input_args[0]);
		free(input_line);
		shell_excute(prog_path, input_args, envp);
		free_my_array(input_args);
		free(input_args);
		free(prog_path);
	}
}

/**
 * non_interactive_shell - controll the shell in the non interactive mode
 * @envp: the evironment array
 * Description: handle the shell
*/

void non_interactive_shell(char **envp)
{
	char *input_line, *prog_path;
	char **input_args;
	int shell_status = 1;

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		buffer[bytes_read - 1] = '\0';
		input_args = get_shell_args(buffer);
		if (input_args != NULL)
		{
			prog_path = malloc(strlen(input_args[0]) + strlen("/bin/") + 1);
			if (prog_path == NULL)
			{
				perror("malloc error");
				exit(EXIT_FAILURE);
			}
			strcpy(prog_path, "/bin/");
			strcat(prog_path, input_args[0]);
			shell_excute(prog_path, input_args, envp);
			free_my_array(input_args);
			free(input_args);
			free(prog_path);
		}
	}
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
	if (strcmp(input_args[0], "env") == 0)
	{
		int i = 0;

		while (envp[i] != NULL)
		{
			printf("%s\n", envp[i]);
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
	if (strcmp(input_args[0], "exit") == 0)
	{
		if (input_args[1] == NULL)
		{
			free(input_line);
			free_my_array(input_args);
			free(input_args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
