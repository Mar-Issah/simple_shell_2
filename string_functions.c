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
