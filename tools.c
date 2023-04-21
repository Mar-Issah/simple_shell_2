#include "shell.h"

/**
 * Writes an error message to the specified file descriptor indicating that the given command was not found.
 *
 * @param fd the file descriptor to write the error message to
 * @param command the name of the command that was not found
 */

void print_error(int fd, char *command)
{
    char *error_msg = ": command not found\n";

    write(fd, command, _strlen(command));
    write(fd, error_msg, _strlen(error_msg));
}
