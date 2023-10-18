#include "main.h"
/**
 * strdup_path - strdup
 * @str : string
 * Return: Pointer to char
 */
char *strdup_path(char *str, char *user_input)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + _strlen(user_input) + 2;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
        free(dupl);
		return (NULL);
	}
	strcpy_path(dupl, str, user_input);
	return (dupl);
}
