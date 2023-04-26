#include "shell.h"
/**
* _strtok - function which is used to tokenize a string
* @str: a pointer to the string to be tokenized
* @delim: pointer to the delimiter character
*
* Return: a pointer to the next token in the string
*/

char *_strtok(char *str, char *delim)
{
static char *last_str;
char *tok;

if (str != NULL)
{
last_str = str;
}
else
{
if (last_str == NULL)
{
return (NULL);
}
str = last_str;
}
while (*str && _strchr(delim, *str))
{
++str;
}
if (!*str)
{
return (NULL);
}
tok = str;

while (*str && !_strchr(delim, *str))
{
++str;
}
if (*str)
{
*str = '\0';
last_str = str + 1;
}
else
{
last_str = NULL;
}
return (tok);
}
