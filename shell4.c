#include "main.h"
/**
 * execute - Execute a command using execve
 * @token_array: An array of tokens representing the command
 * @argv: The program's arguments
 * Return: The exit status of the executed command
 */
int execute(char **token_array, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("FORK ERROR");
		exit(-1);
	}
	else if (pid == 0)
	{
		if (execve(token_array[0], token_array, environ) == -1)
		{
			perror(argv[0]);
			free_array(token_array);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return WEXITSTATUS(status);
}

/**
 * tokenizeline - Tokenize a string using the specified delimiters
 * @input: The input string
 * @delimiters: The delimiters to use
 * Return: Tokenized array of strings
 */
char **tokenizeline(char *input, char *delimiters)
{
	char **tokenized_input = NULL;
	char *str_copy = NULL;
	char *token = NULL;
	int count_token = 0;
	int i = 0;

	if (input == NULL)
	{
		return NULL;
	}
	
	str_copy = _strdup(input);
	token = strtok(str_copy, delimiters);
	while (token != NULL)
	{
		count_token++;
		token = strtok(NULL, delimiters);
	}
	free(str_copy);
	str_copy = NULL;
	tokenized_input = malloc(sizeof(char *) * (count_token + 1)); /* Removed the +1 but added again */
	if (tokenized_input == NULL)
	{
		free(input);
		return NULL;
	}
	token = strtok(input, delimiters);
	while (token != NULL)
	{
		tokenized_input[i] = _strdup(token);
		token = strtok(NULL, delimiters);
		i++;
	}
	tokenized_input[i] = NULL;
	free(input);
	input = NULL;
	return tokenized_input;
}

/**
 * execute_path - Execute a command with a specified path
 * @input_array: An array of tokens representing the command
 * @argv: The program's arguments
 * @path: The path to the executable
 * Return: The exit status of the executed command
 */
int execute_path(char **input_array, char **argv, char *path)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("FORK ERROR");
		exit(-1);
	}
	else if (pid == 0)
	{
		if (execve(path, input_array, environ) == -1)
		{
			perror(argv[0]);
			free_array(input_array);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return WEXITSTATUS(status);
}

/**
 * access_ok - Check if the current user has execute permission on any of the paths
 * @paths: An array of paths
 * Return: The index of a path with execute permission, -1 for no path, -2 for no permission
 */
int access_ok(char **paths)
{
	int i = 0;
	int permission;

	if (!paths)
	{
		perror("NO PATH");
		return -1;
	}

	while (paths[i])
	{
		permission = access(paths[i], X_OK);
		if (permission == 0)
		{
			return i; 
		}
		else
		{
			;
		}
		i++;
	}
	return -2;
}

/**
 * exec_cmd - Execute a command with a specified path if access permissions are granted
 * @paths: An array of paths
 * @argv: The program's arguments
 * @tokenized_input: An array of tokens representing the command
 * Return: 0 for success, -1 for failure
 */
int exec_cmd(char **paths, char **argv, char **tokenized_input)
{
	int index;
	index = access_ok(paths);
	if (index >= 0)
	{
		execute_path(tokenized_input, argv, paths[index]);
	}
	else if (index < 0)
	{
		return -1;
	}

	return 0; /* Success */
}