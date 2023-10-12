#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
int main(void)
{
	char *input = NULL,*token = NULL;
	size_t input_size = 0;
	char delimiters[] = " ";
	char **tokenized_input = NULL;
	int i = 0, j = 0;

	while (1)
	{
		_puts("$ ");

		if (getline(&input, &input_size, stdin) == -1)
		{
			free(input);
			return (-1);
		}

		token = strtok(input, delimiters);
		while (token != NULL)
		{
			tokenized_input = _realloc(tokenized_input, i * (sizeof(char *)), (i + 1) * sizeof(char *));
			tokenized_input[i] = _strdup(token);
			i++;
			token = strtok(NULL, delimiters);
		}

		for (j = 0; j < i; j++)
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
