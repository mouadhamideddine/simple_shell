#include "main.h"
/**
 * _strdup - Duplicate
 * @str: The
 * Return: Pointer
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

/**
 * _strncmp - strings
 * @str_unknown_size: string
 * @str_known_size: string
 * @n: characters to compare
 * Return: 0
 */
int _strncmp(char *str_unknown_size, char *str_known_size, int n)
{
	int i = 0;

	if (!str_known_size || !str_unknown_size)
	{
		perror("_STRNCMP ERROR");
		return (1);
	}
	if (_strlen(str_unknown_size) < n)
	{
		perror("_STRNCMP n > str_unknown_size");
		return (1);
	}
	while (str_unknown_size[i] != '\0' && n > 0)
	{
		n--;
		if (str_known_size[i] != str_unknown_size[i])
		{
			return (-1); /* Difference */
		}
		i++;
	}
	return (0); /* Match */
}

/**
 * strcpy_path - input
 * @destination: string
 * @source: string
 * @userinput: string
 * Return: string
 */
char *strcpy_path(char *destination, char *source, char *userinput)
{
	int i_dest = 0;
	int i_userinput = 0;
	int i_source = 0;

	while (source[i_source])
	{
		destination[i_dest] = source[i_source];
		i_source++;
		i_dest++;
	}
	destination[i_dest] = '/';
	i_dest++;
	while (userinput[i_userinput] && iswhite(userinput[i_userinput] == -1))
	{
		i_userinput++;
	}
	while (userinput[i_userinput] && iswhite(userinput[i_userinput]) == 0)
	{
		destination[i_dest] = userinput[i_userinput];
		i_userinput++;
		i_dest++;
	}
	destination[i_dest] = '\0';
	return (destination);
}

/**
 * strdup_path -  a user input
 * @str: duplicate
 * @user_input: string
 * Return: string
 */
char *strdup_path(char *str, char *user_input)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + strlen_forpath(user_input) + 2; /* +1 only not +2 */
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		free(dupl);
		return (NULL);
	}
	strcpy_path(dupl, str, user_input);
	return (dupl);
}

/**
 * remove_PATH -environment variable
 * @firsttoken: variable
 * Return: string
 */
char *remove_PATH(char *firsttoken)
{
	return (firsttoken + 5);
}
