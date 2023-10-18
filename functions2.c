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
		rm_comment(input_line);
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
		if (!is_help(input_args, input_line))
			continue;
		if (!is_setenv(input_args, input_line))
			continue;
		if (!is_unsetenv(input_args, input_line))
			continue;
		prog_path = malloc(_strlen(input_args[0]) + _strlen("/bin/") + 1);
		if (prog_path == NULL)
			perror("malloc error"), exit(EXIT_FAILURE);

		_strcpy(prog_path, "/bin/");
		_strcat(prog_path, input_args[0]);
		free(input_line);
		shell_excute(prog_path, input_args, envp);
		free_my_array(input_args), free(input_args), free(prog_path);
	}
}

/**
 * non_interactive_shell - controll the shell in the non interactive mode
 * @envp: the evironment array
 * Description: handle the shell
 */

void non_interactive_shell(char **envp)
{
	char *prog_path;
	char **input_args;

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		buffer[bytes_read - 1] = '\0';
		input_args = get_shell_args(buffer);
		if (input_args != NULL)
		{
			prog_path = malloc(_strlen(input_args[0]) + _strlen("/bin/") + 1);
			if (prog_path == NULL)
			{
				perror("malloc error");
				exit(EXIT_FAILURE);
			}
			_strcpy(prog_path, "/bin/");
			_strcat(prog_path, input_args[0]);
			shell_excute(prog_path, input_args, envp);
			free_my_array(input_args);
			free(input_args);
			free(prog_path);
		}
	}
}
