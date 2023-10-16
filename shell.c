#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/*
int main(int ac, char **argv)
{
	char *input = NULL;
	int status = 0;
	(void)ac;
	(void)argv;

	while(1)
	{
		input = readline();
		if (input == NULL)
		{
			if(isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return(status);
		}
	}
}
*/
int main(int ac, char **argv)
{
	(void)ac;
	char *input = NULL;
	size_t input_size = 0;
	char delimiters[] = {' ', '\t', '\n', '\0'};
	char dollar[] = {"$ "};
	char **tokenized_input = NULL;
	int status = 0;
	ssize_t read;

	while (1)
	{
		input = readline();
		if (input == NULL)
		{
			if(isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			/*free(input);*/
			return(status);
		}
		/*printf("here");*/
		tokenized_input = tokenizeline(input, delimiters);
		/*printf("tokenized_input%s", tokenized_input[0]);*/
		if (tokenized_input != NULL)
		{
			execute(tokenized_input, argv);
		}
		free_array(tokenized_input);
		/*free(input);*/
		/*input = NULL;*/
		tokenized_input = NULL;
	}
	return (status);
}
/*
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char delimiters[] = " ,\t,\n";
	char dollar[] = {"$ "};
	char **tokenized_input = NULL;
	char *path = NULL;
	int status = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO,"$ ",2);
		read = getline(&input, &input_size, stdin);
		if (read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(input);
			return(status);
		}
		tokenized_input = tokenizeline(input, delimiters);
		//printf("tokenized_input%s", tokenized_input[0]);
		if (tokenized_input != NULL)
		{
			execute(tokenized_input);
		}
		free_array(tokenized_input);
		//free(input);
		tokenized_input = NULL;
	}
	//free(input);
	printf("this");
	return (status);
}
*/