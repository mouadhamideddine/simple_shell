#include "main.h"
#include <stdlib.h>
/**
 * _strdup - strdup
 * @str : string
 * Return: Pointer to char
 */
char *_strdup(char *str)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + 1;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		return (NULL);
	}

	_strcpy(dupl, str);
	return (dupl);
}
