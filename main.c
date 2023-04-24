#include "shell.h"

/**
 * main - the main function/ entry point
 *
 * Return: (Success) 0 
 */
int main()
{
    char *line;
    char *command;
    char **args;
    int arg_count = 0;
    int exit_status = 0;

    while (1)
    {
        line = read_command();
        if (line != NULL && _strlen(line) > 0)
        {
            args = malloc(sizeof(char *) * 64);
            arg_count = 0;
            command = _strtok(line, " \t\n");
            while (command != NULL)
            {
                args[arg_count++] = command;
                command = _strtok(NULL, " \t\n");
            }
            args[arg_count] = NULL;

            if (_strcmp(args[0], "exit") == 0)
            {
                if (args[1] != NULL)
                {
                    exit_status = _atoi(args[1]);
                }
                free(line);
                free(args);
                exit(exit_status);
            }
             else if (_strcmp(args[0], "cd") == 0)
             {
                cd_builtin(args);
            } else
             {
                execute_command(args);
            }
            free(args);
        }
        free(line);
    }
    return (EXIT_SUCCESS);
}
