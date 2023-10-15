#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

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


        



