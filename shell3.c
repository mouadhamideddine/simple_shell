#include "main.h"
/**
 * print2DArray - Print a 2D array of strings
 * @arr: The 2D array
 */
void print2DArray(char ***arr)
{
	int row = 0;
	while (arr[row] != NULL)
	{
		int col = 0;
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
 * tokenize_path - Tokenize a string using ':' as the delimiter
 * @fullpath: The full path string
 * @user_input: User input string
 * Return: Tokenized array of strings
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
		return NULL;
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
	tokenized_fullpath = malloc(sizeof(char *) * (count_token + 1)); /* for NULL */
	if (tokenized_fullpath == NULL)
	{
		return NULL;
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
	path_copy = NULL;
	/* free(fullpath); reason it's environ[i] */
	/* fullpath = NULL; reason it's environ[i] */
	return tokenized_fullpath; /* a tokenized full path ready for access */
}

/**
 * is_path - Check if a string represents a path
 * @input: The string to check
 * Return: 1 if it's a path, 0 if it's not
 */
int is_path(char *input)
{
	int i = 0;
	if (!input)
	{
		return -1; /* Invalid input */
	}
	while (input[i])
	{
		if (input[i] == '\\' || (input[i] == '/'))
		{
			return 1; /* Path */
		}
		i++;
	}
	return 0; /* Not a path */
}

/**
 * get_path - Get the PATH environment variable
 * Return: The PATH environment variable
 */
char *get_path(void)
{
	char path_indic[] = "PATH=";
	int i = 0;
	
	while (environ[i])
	{
		if (_strncmp(environ[i], path_indic, 5) == 0)
		{
			return environ[i];
		}
		i++;
	}
	return NULL;
}

/**
 * readline - Read a line from the standard input
 * Return: The input line
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
		return NULL;
	}
	return line;
}