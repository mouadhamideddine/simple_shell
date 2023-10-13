#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

extern char** environ;

int main(void)
{
	char *input = NULL,*token = NULL;
	size_t input_size = 0;
	char delimiters[] = " ";
	char **tokenized_input = NULL, *test[10];
	int i = 0, j = 1, k =0;

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
		test[0] = tokenized_input[0];
		while (tokenized_input[j])
		{
			test[k] = tokenized_input[j];
			k++;
			j++;
		}
		test[k] = "\0";
		if(execve("/bin/ls", test, environ) == -1)
		{
			printf("execve %s %s ", tokenized_input[0], tokenized_input[1]);
		}
		free(tokenized_input);
		tokenized_input = NULL;
		i = 0;
	}

	free(input);
	return (0);
}
