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

char *search_command(char *command)
{
    char *path_env = _getenv("PATH");
    char *path_env_copy = _strdup(path_env);
    char *path = strtok(path_env_copy, ":");
    char *full_path = malloc(PATH_MAX);
    int path_len, command_len;


    while (path) {
         path_len = _strlen(path);
        _memcpy(full_path, path, path_len);
        full_path[path_len] = '/';
        command_len = _strlen(command);
        _memcpy(full_path + path_len + 1, command, command_len);
        full_path[path_len + 1 + command_len] = '\0';
        
        
        if (access(full_path, X_OK) == 0)
        {
            free(path_env_copy);
            return full_path;
        }
        path = strtok(NULL, ":");
    }
    free(path_env_copy);
    free(full_path);
    
    return (NULL);
}


/**
 * execute_command - function to execute the command
 * @command: command to be executed
 * Fail: Exit
 */
void execute_command(char *command_line)
{
    pid_t pid;
    int status;
    char *token;
    char **args;
    int arg_count = 0;
    char *full_path;

    args = malloc(sizeof(char *) * 64);
    if (!args)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(command_line, " \t");
    while (token) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " \t");
    }
    args[arg_count] = NULL;

    full_path = search_command(args[0]);
    if (!full_path) {
        /* fprintf(stderr, "%s: command not found\n", args[0]);*/
        print_error(STDERR_FILENO, args[0]);
        free(args);
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0)
    {
        /*-- Child process--*/
        if (execve(full_path, args, environ) == -1)
        {
            /* fprintf(stderr, "%s: command execution failed\n", args[0]);*/
            print_error(STDERR_FILENO, args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /*-- Parent process--*/
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }


    free(args);
    free(full_path);
}
