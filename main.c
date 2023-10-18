#include "main.h"
/*
 * main - main
 * @ac : ac
 * @argv: argv
 * Return: int
 */
int main(int ac, char **argv)
{
	char delimiters[] = {' ', '\t', '\n', '\0'};
	char **tokenized_input = NULL;
	char **tokenized_path = NULL;
	int status = 0, path_token;
	char *path = NULL;
	char *input = NULL;
	(void)ac;
	
	while (1)
	{
		input = readline();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return status;
		}
		path_token = is_path(input);
		if (path_token == 1)
		{
			tokenized_input = tokenizeline(input, delimiters);
			execute(tokenized_input, argv);
			free_array(tokenized_input);
			tokenized_input = NULL;
		}
		else if (path_token == 0)
		{
			path = get_path();
			tokenized_path = tokenize_path(path, input);
			tokenized_input = tokenizeline(input, delimiters);
			exec_cmd(tokenized_path, argv, tokenized_input);
			free_array(tokenized_input);
			free_array(tokenized_path);
		}		
	}
	return status;
}