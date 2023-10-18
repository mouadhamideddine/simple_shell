#include "main.h"
/**
 * print2DArray -strings
 * @arr:array
 */
void print2DArray(char ***arr)
{
	int row = 0;
	int col = 0;

	while (arr[row] != NULL)
	{
		while (arr[row][col] != NULL)
		{
			printf("2D%s \n", arr[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

/**
 * tokenize_path -delimiter
 * @fullpath: string
 * @user_input: string
 * Return: strings
 */
char **tokenize_path(char *fullpath, char *user_input)
{
	char **tokenized_fullpath = NULL;
	char *path_copy = NULL;
	char *token = NULL;
	int count_token = 0;
	int i = 0;

	if (fullpath == NULL)
	{
		return (NULL);
	}

	path_copy = _strdup(fullpath);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		count_token++;
		token = strtok(NULL, ":");
	}
	free(path_copy);
	path_copy = NULL;
	tokenized_fullpath =
		malloc(sizeof(char *) * (count_token + 1));
	if (tokenized_fullpath == NULL)
{
		return (NULL);
	}
	path_copy = _strdup(fullpath);
	token = strtok(path_copy, ":");
	token = remove_PATH(token);
	while (token != NULL)
	{
		tokenized_fullpath[i] = strdup_path(token, user_input);
		token = strtok(NULL, ":");
		i++;
	}
	tokenized_fullpath[i] = NULL;
	free(path_copy);
	path_copy = (NULL);
	return (tokenized_fullpath); /* a tokenized full path ready for access */
}

/**
 * is_path - Check
 * @input: check
 * Return: path
 */
int is_path(char *input)
{
	int i = 0;

	if (!input)
	{
		return (-1); /* Invalid input */
	}
	while (input[i])
	{
		if (input[i] == '\\' || (input[i] == '/'))
		{
			return (1); /* Path */
		}
		i++;
	}
	return (0); /* Not a path */
}

/**
 * get_path - variable
 * Return: variable
 */
char *get_path(void)
{
	char path_indic[] = "PATH=";
	int i = 0;

	while (environ[i])
	{
		if (_strncmp(environ[i], path_indic, 5) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * readline -  input
 * Return: line
 */
char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
