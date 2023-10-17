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

/*strings1.c*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
void _strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *str1, char *str2);

/*strings2.c*/
void _puts(char *str);

/*built-ins.c*/
int is_cd(char **input_arg, char *input_line);
int is_env(char **input_args, char *input_line, char *envp[]);
int is_exit(char **input_args, char *input_line);
int is_help(char **input_args, char *input_line);

/*functions.c*/
char **get_shell_args(char *shell_line);
char *get_shell_line(void);
void shell_excute(char *path, char **args, char *envp[]);
void free_my_array(char **args);

/*funcitons2.c*/
void non_interactive_shell(char **envp);
void interactive_shell(char **envp);

#endif
