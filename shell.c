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
	char dollar[] = {"$ "};
	char **tokenized_input = NULL;
	char *path = NULL;
	int status = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO,dollar,2);
		read = getline(&input, &input_size, stdin);
		//printf("%d", read);
		if (read == -1)
		{
			free(input);
			return(status);
		}
		if (read > 0){
		tokenized_input = tokenizeline(input, delimiters);
		//printf("tokenized_input%s", tokenized_input[0]);
		execute(tokenized_input);
		free_array(tokenized_input);
		tokenized_input = NULL;}
	}

	free(input);
	return (status);
}


        



