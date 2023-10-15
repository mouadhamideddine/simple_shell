#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while(token)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    tokenized_input = malloc(sizeof(char *) * count_token);
    free(str_copy);
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while (token)
    {
        tokenized_input[i] = _strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }

    free(str_copy);
    return (tokenized_input);
} 



int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char delimiters[] = " ,\t,\n";
	char **tokenized_input = NULL;
	char *path = NULL;

	while (1)
	{
		_puts("$ ");

		if (getline(&input, &input_size, stdin) == -1)
		{
			free(input);
			return (-1);
		}
		tokenized_input = tokenizeline(input, delimiters);
		execve(tokenized_input[0],tokenized_input,NULL);
		free(tokenized_input);
		tokenized_input = NULL;
	}

	free(input);
	return (0);
}
