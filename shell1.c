#include "main.h"

/**
 * iswhite - Check
 * @c: The
 * Return: -1
 */
int iswhite(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (-1);
	}
	return (0);
}

/**
 * strlen_forpath - Calculate
 * @user_input: The
 * Return: Length
 */
int strlen_forpath(char *user_input)
{
	int i = 0;
	int length = 0;

	if (!user_input)
	{
		perror("!user_input strlen_forpath");
	}
	while (user_input[i] && iswhite(user_input[i]) == -1)
	{
		i++;
	}
	while (user_input[i] && iswhite(user_input[i]) == 0)
	{
		length++;
		i++;
	}
	return (length);
}

/**
 * free_array - Free
 * @array: The array
 * Return: 0
 */
int free_array(char **array)
{
	int i = 0;

	if (array == NULL)
	{
		return (0);
	}

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return (0);
}

/**
 * _strlen - length
 * @s:string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (s[longi] != '\0')
	{
		longi++;
	}

	return (longi);
}

/**
 * _strcpy - Copy
 * @dest: string
 * @src: string
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for (; x < l; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
