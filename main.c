#include "shell.h"

/**
 * main - the entering point function
 * @argc: number of args passed
 * @argv: arguments
 * @envp: environment variables
 * Return: 1
 */

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;

	if (!isatty(fileno(stdin)))
	{
		non_interactive_shell(envp);
		return (EXIT_SUCCESS);
	}
	interactive_shell(envp);

	return (EXIT_SUCCESS);
}
