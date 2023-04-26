#include "shell.h"

/**
* main - the main function/ entry point
*
* Return: (Success) 0
*/
int main(void)
{
char *line;
char *command;
char **args;
int arg_count = 0;
int exit_status = 0;
char **commands;

while (1)
{
int i = 0;
line = read_command();
commands = parse_commands(line);

while (commands[i])
{
command = _strtok(commands[i], "\n");

if (command != NULL && _strlen(command) > 0)
{
args = malloc(sizeof(char *) * 64);
arg_count = 0;
args[arg_count++] = _strtok(command, " \t");

while ((args[arg_count++] = _strtok(NULL, " \t")));

if (_strcmp(args[0], "exit") == 0)
{
if (args[1] != NULL)
{
exit_status = _atoi(args[1]);
}
free(line);
free(args);
free(commands);
exit(exit_status);
}
else if (_strcmp(args[0], "cd") == 0)
{
cd_builtin(args);
}
else
{
execute_command(args);
}
free(args);
}
i++;
}
free(line);
free(commands);
}
return (EXIT_SUCCESS);
}
