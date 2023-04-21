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

/**
 * _getenv - gets the path
 * @path_name: a pointer to the struct of data
 *
 * Return: Success, a positive number
 * Fail, a negative number
 */
char *_getenv(char *path_name)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}

/**
 * _memcpy - copies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: A pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
