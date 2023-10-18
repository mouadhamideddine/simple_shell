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
char** tokenizeline(char* input, char* delimiters)
{
    char **tokenized_input = NULL;
    char *str_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;

    if (input == NULL)
    {
        return(NULL);
    }
    
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while(token != NULL)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    free(str_copy);
    str_copy = NULL;
    tokenized_input = malloc(sizeof(char *) * (count_token + 1)); /*removed the +1 but add again*/
    if (tokenized_input == NULL)
    {
        free(input);
        return(NULL);
    }
    token = strtok(input, delimiters);
    while (token != NULL)
    {
        tokenized_input[i] = _strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }
    tokenized_input[i] = NULL;
    free(input);
    input = NULL;
    return (tokenized_input);
} 

int _strncmp(char *str_unknown_size, char *str_known_size, int n)
{
    int i = 0;

    if(!str_known_size || !str_unknown_size)
    {
        perror("_STRNCMP ERROR");
        return (1);
    }
    if(strlen(str_unknown_size) < n)
    {
        perror("_STRNCMP n > str_unkonw_size");
        return (1);
    }
    while(str_unknown_size[i] != '\0' && n > 0)
    {
        n--;
        if(str_known_size[i] != str_unknown_size[i])
        {
            return(-1); /*difference*/
        }
        i++;
    }
    return (0); /*match*/
}

