#include "shell.h"
/**
* print_error - Writes an error message
*
* @fd: the file descriptor to write the error message to
* @command: the name of the command that was not found
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

/**
* _getline - Read a line of input from a stream
* @lineptr: a pointer to a pointer to a buffer
* @n: pointer to the size of the buffer
* @stream: a pointer to the input stream to read from
*
* Return: the number of characters read from the stream
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
static char buffer[BUFFER_SIZE];
static int buffer_pos;
static int buffer_len;
int line_pos = 0;
int c;

if (lineptr == NULL || n == NULL || stream == NULL)
return (-1);
if (*lineptr == NULL || *n == 0)
{
*n = BUFFER_SIZE;
*lineptr = malloc(*n);
if (*lineptr == NULL)
return (-1);
}
while (1)
{
if (buffer_pos >= buffer_len)
{
buffer_len = read(fileno(stream), buffer, BUFFER_SIZE);
if (buffer_len <= 0)
return (buffer_len);
buffer_pos = 0;
}
c = buffer[buffer_pos++];
(*lineptr)[line_pos++] = c;
if (line_pos >= (int)(*n - 1))
{
*n += BUFFER_SIZE;
*lineptr = realloc(*lineptr, *n);
if (*lineptr == NULL)
return (-1);
}
if (c == '\n')
{
break;
}
}
(*lineptr)[line_pos] = '\0';
return ((ssize_t)line_pos);
}

/**
* _atoi - converts character to integer
* @c: the given character
*
* Return: An integer
*/
int _atoi(char *c)
{
unsigned int val = 0;
int sign = 1;

if (c == NULL)
return (0);
while (*c)
{
if (*c == '-')
sign *= (-1);
else
val = (val * 10) + (*c - '0');
c++;
}
return (sign *val);
}
