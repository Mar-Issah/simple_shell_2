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

/* Global variable */
extern char **environ;

/*-- util functions to read and execute commands ---*/
char *read_command();
void execute_command(char *command);

/* ------String function prototype------*/
int _strlen(char *str);
char *_strcpy(char *destination, char *source);
char *_strdup(char *str);

/* ------Tools------*/
void print_error(int fd, char *command);
char *_getenv(char *path_name);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* SHELL_H */
