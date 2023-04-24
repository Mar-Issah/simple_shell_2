#include "shell.h"

/**
 * _strlen - function that find the length of a string
 * @str: the given string
 */
int _strlen(char *str)
{
	int len;
  
	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcpy - copie a string from source to destination
 * @source: the string source
 * @destination: the string destination
 *
 * Return: the pointer to destination
 */
char *_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return (destination);
}


/**
 * _strdup - dupicates string
 * @str: the given string
 *
 * Return: (Success) a pointer to the duplicated string
 * ------- (Fail) return a null pointer
 */
char *_strdup(char *str)
{
	char *duplicate;

	if (str == NULL)
		return (NULL);
	duplicate = malloc(_strlen(str) + 1);
	if (duplicate == NULL)
		return (NULL);
	_strcpy(duplicate, str);
	return (duplicate);
}

/**
  * _strcmp - a function to compare two strings
  * @s1: the first string
  * @s2: the second string
  *
  * Return: int
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		break;
	}
	return (*s1 - *s2);
}

/**
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the given string
 *
 * Return: a pointer to the first occurence of c
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}

/*
* _strtok: function which is used to tokenize a string
* @str: a pointer to the string to be tokenized
* @delim: pointer to the delimiter character
*
* return: a pointer to the next token in the string
*/

char *_strtok(char *str, const char *delim)
{
    static char *last_str = NULL;
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

    if (!*str) {
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
