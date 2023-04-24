#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

#define PRINT(char) (write(STDOUT_FILENO, char, _strlen(char)))
#define BUFFER_SIZE 1024

/* Global variable */
extern char **environ;

/*-- util functions to read and execute commands ---*/
char *read_command();
void execute_command(char **command);

/* ------String function prototype------*/
int _strlen(char *str);
char *_strcpy(char *destination, char *source);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *str, char c);
char *_strtok(char *str, char *delim);

/* ------Tools------*/
void print_error(int fd, char *command);
char *_getenv(char *path_name);
char *_memcpy(char *dest, char *src, unsigned int n);
char *search_command(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _atoi(char *c);
void cd_builtin(char **args);

#endif /* SHELL_H */
