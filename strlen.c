#include "main.h"
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
