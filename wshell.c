#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

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

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
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

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

char *_strdup(char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}

	int size = _strlen(str) + 1;
	char *dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		return (NULL);
	}

	_strcpy(dupl, str);
	return (dupl);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	char *ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	char *old_ptr = ptr;

	if (new_size < old_size)
	{
		for (unsigned int i = 0; i < new_size; i++)
			ptr1[i] = old_ptr[i];
	}
	else
	{
		for (unsigned int i = 0; i < old_size; i++)
			ptr1[i] = old_ptr[i];
	}

	free(ptr);
	return (ptr1);
}

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char delimiters[] = " ";
	char **tokenized_input = NULL;
	int i = 0;

	while (1)
	{
		_puts("$ ");

		if (getline(&input, &input_size, stdin) == -1)
		{
			free(input);
			return (-1);
		}

		char *token = strtok(input, delimiters);
		while (token != NULL)
		{
			tokenized_input = _realloc(tokenized_input, i * (sizeof(char *)), (i + 1) * sizeof(char *));
			tokenized_input[i] = _strdup(token);
			i++;
			token = strtok(NULL, delimiters);
		}

		for (int j = 0; j < i; j++)
		{
			printf("Token %d: %s\n", j, tokenized_input[j]);
			free(tokenized_input[j]);
		}

		free(tokenized_input);
		tokenized_input = NULL;
		i = 0;
	}

	free(input);
	return (0);
}

