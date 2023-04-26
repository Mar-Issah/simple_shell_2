#include "shell.h"
/*
 * cd_builtin - function that implement 'cd'
 *   args - an array of strings containing the command and argument(s)
 *
 * Return value: none
 */
void cd_builtin(char **args)
{
    char *new_directory;
    char *old_directory;
    char *home_directory;
    char current_directory[BUFFER_SIZE];

    if (args[1] == NULL || _strcmp(args[1], "~") == 0 || _strcmp(args[1], "$HOME") == 0)
    {
        home_directory = _getenv("HOME");
        new_directory = home_directory;
    } else if (_strcmp(args[1], "-") == 0)
    {
        new_directory = _getenv("OLDPWD");
        PRINT(new_directory);
    } else
    {
        new_directory = args[1];
    }
	
    old_directory = getcwd(current_directory, sizeof(current_directory));
    if (old_directory == NULL)
    {
        perror("getcwd");
        return;
    }

    if (chdir(new_directory) != 0)
    {
        perror("chdir");
        return;
    }
	
    if (setenv("PWD", new_directory, 1) == -1)
    {
        perror("setenv");
        return;
    }

    if (setenv("OLDPWD", old_directory, 1) == -1)
    {
        perror("setenv");
        return;
    }
}
