#include "main.h"

/**
 * iswhite - Check if a character is a white space character
 * @c: The character to check
 * Return: -1 if it's white, 0 otherwise
 */
int iswhite(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (-1);
	}
	return 0;
}

/**
 * strlen_forpath - Calculate the length of a string until the first white space character
 * @user_input: The input string
 * Return: Length of the string
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
	return length;
}

/**
 * free_array - Free a null-terminated array of strings and the array itself
 * @array: The array to be freed
 * Return: 0 for success
 */
int free_array(char **array)
{
	int i = 0;

	if (array == NULL)
	{
		return 0;
	}

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return 0;
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int longi = 0;

	while (s[longi] != '\0')
	{
		longi++;
	}

	return longi;
}

/**
 * _strcpy - Copy one string into another
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the destination string
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
	return dest;
}
