#include "shell.h"

/**
 * main - the main function/ entry point
 *
 * Return: (Success) 0 
 */
int main() {
    char *line;
    char *command;

    while (1) {
        line = read_command();
        command = strtok(line, "\n");
      
        if (command != NULL && _strlen(command) > 0) {
              if (_strcmp(command, "exit") == 0)
              {
                free(line);
                exit(EXIT_SUCCESS);
            }
            execute_command(command);
        }
        free(line);
    }
    return (EXIT_SUCCESS);
}
