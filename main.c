#include "shell.h"

/**
 * main - fu
 * @argc: input int
 * @argv: input array of strings
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
