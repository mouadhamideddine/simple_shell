#include "main.h"
/**
 * execute - Execute
 * @token_array:  command
 * @argv: arguments
 * Return: executed command
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
			/*perror(argv[0]);*/
			free_array(token_array);
		    exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (WEXITSTATUS(status));
}

/**
 * tokenizeline -  delimiters
 * @input: string
 * @delimiters: use
 * Return: strings
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
		return (NULL);
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
	tokenized_input =
		malloc(sizeof(char *) * (count_token + 1));
	if (tokenized_input == NULL)
	{
		free(input);
		return (NULL);
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
	return (tokenized_input);
}

/**
 * execute_path -  path
 * @input_array: command
 * @argv: arguments
 * @path: executable
 * Return: command
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
	return (WEXITSTATUS(status));
}

/**
 * access_ok -paths
 * @paths: paths
 * Return:  no permission
 */
int access_ok(char **paths)
{
	int i = 0;
	int permission;

	if (!paths)
	{
		perror("NO PATH");
		return (-1);
	}

	while (paths[i])
	{
		permission = access(paths[i], X_OK);
		if (permission == 0)
		{
			return (i);
		}
		else
		{
			;
		}
		i++;
	}
	return (-2);
}

/**
 * exec_cmd -  granted
 * @paths: aths
 * @argv: arguments
 * @tokenized_input: the command
 * Return: 0
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
		return (-1);
	}

	return (0); /* Success */
}
