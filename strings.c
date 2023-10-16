#include "main.h"
#include <stdlib.h>
/**
 * _strlen - calculate str length
 * @s : string
 * Return: int
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}
/**
 * _strcpy - copy string
 * @dest : destination
 * @src : source
 * Return: Pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
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
