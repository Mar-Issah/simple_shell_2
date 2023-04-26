#include "shell.h"
/*
* parse_commands - function takes in a string line that contains
* multiple commands separated by ';'
* @line: string line
* The array is terminated by a NULL pointer.
* Return: the array of strings containing each individual command
*/
char **parse_commands(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = _strtok(line, ";");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("realloc");
exit(EXIT_FAILURE);
}
}

token = _strtok(NULL, ";");
}
tokens[position] = NULL;
return (tokens);
}
