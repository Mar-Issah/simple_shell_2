#include "shell.h"

/**
 * main - the main function/ entry point
 *
 * Return: (Success) 0 
 */
int main() {
    char *line;
    char *command;
    char **args;
    int arg_count = 0;
    int exit_status = 0;

    while (1) {
        line = read_command();
        command = _strtok(line, "\n");
      
        if (command != NULL && _strlen(command) > 0) {
            args = malloc(sizeof(char *) * 64);
            arg_count = 0;
            args[arg_count++] = _strtok(command, " \t");
            
             while ((args[arg_count++] = _strtok(NULL, " \t")))
                 ;
            
              if (_strcmp(args[0], "exit") == 0) 
               {
                if (args[1] != NULL) {
                    exit_status = _atoi(args[1]);
                }
                free(line);
                free(args);
                exit(exit_status);
            }
            execute_command(command);
            free(args);
        }
        free(line);
    }
    return (EXIT_SUCCESS);
}
