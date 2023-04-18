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
