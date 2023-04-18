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
            execute_command(command);
        }
        free(line);
    }
    return EXIT_SUCCESS;
}
