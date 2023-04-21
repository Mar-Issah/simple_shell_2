#include "shell.h"

/**
 * read_command - prompt function to display the prompt and read input:
 * FAIL: exit
 * Return: (Success) 0 a
 */
char *read_command()
{
    char *line = NULL;
    size_t bufsize = 0;

    PRINT("$ ");
    if (getline(&line, &bufsize, stdin) == -1) 
    {
        if (line == NULL || line[0] == '\0')
        {
            PRINT("\n");
            exit(EXIT_SUCCESS);
        } else {
            perror("read_command");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

/**
 * execute_command - function to execute the command
 * @command: command to be executed
 * Fail: Exit
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /*-- Child process--*/
        if (execlp(command, command, NULL) == -1)
        {
            fprintf(stderr, "%s: command not found\n", command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /*-- Parent process--*/
        do
        {
            waitpid(pid, &status, WUNTRACED);
        }
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
