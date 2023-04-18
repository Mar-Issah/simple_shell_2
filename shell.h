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

#define PRINT(char) (write(STDOUT_FILENO, char, _strlen(char)))

// util functions to read and execute commands
char *read_command();
void execute_command(char *command);

// string functions prop
int _strlen(char *str);

#endif /* SHELL_H */
