#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>



#define TOKENS_BUFFER 128
#define BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 1024


char **get_shell_args(char *shell_line);
char *get_shell_line(void);

int is_cd(char **input_arg, char *input_line);
int is_env(char **input_args, char *input_line, char *envp[]);
int is_exit(char **input_args, char *input_line);

void shell_excute(char *path, char **args, char *envp[]);

void free_my_array(char **args);

void non_interactive_shell(char **envp);
void interactive_shell(char **envp);

#endif
