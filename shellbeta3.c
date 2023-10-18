#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/**
 * iswhite - Check if a character is a white space character
 * @c: The character to check
 * Return: -1 if it's white, 0 otherwise
 */
int iswhite(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (-1);
	}
	return 0;
}

/**
 * strlen_forpath - Calculate the length of a string until the first white space character
 * @user_input: The input string
 * Return: Length of the string
 */
int strlen_forpath(char *user_input)
{
	int i = 0;
	int length = 0;
	if (!user_input)
	{
		perror("!user_input strlen_forpath");
	}
	while (user_input[i] && iswhite(user_input[i]) == -1)
	{
		i++;
	}
	while (user_input[i] && iswhite(user_input[i]) == 0)
	{
		length++;
		i++;
	}
	return length;
}

/**
 * free_array - Free a null-terminated array of strings and the array itself
 * @array: The array to be freed
 * Return: 0 for success
 */
int free_array(char **array)
{
	int i = 0;

	if (array == NULL)
	{
		return 0;
	}

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return 0;
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int longi = 0;

	while (s[longi] != '\0')
	{
		longi++;
	}

	return longi;
}

/**
 * _strcpy - Copy one string into another
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for (; x < l; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return dest;
}

/**
 * _strdup - Duplicate a string and return a new pointer to the duplicate
 * @str: The string to duplicate
 * Return: Pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return NULL;
	}

	size = _strlen(str) + 1;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		return NULL;
	}

	_strcpy(dupl, str);
	return dupl;
}

/**
 * _strncmp - Compare the first n characters of two strings
 * @str_unknown_size: The unknown size string
 * @str_known_size: The known size string
 * @n: Number of characters to compare
 * Return: 0 if the strings match, -1 if there's a difference
 */
int _strncmp(char *str_unknown_size, char *str_known_size, int n)
{
	int i = 0;

	if (!str_known_size || !str_unknown_size)
	{
		perror("_STRNCMP ERROR");
		return 1;
	}
	if (_strlen(str_unknown_size) < n)
	{
		perror("_STRNCMP n > str_unknown_size");
		return 1;
	}
	while (str_unknown_size[i] != '\0' && n > 0)
	{
		n--;
		if (str_known_size[i] != str_unknown_size[i])
		{
			return -1; /* Difference */
		}
		i++;
	}
	return 0; /* Match */
}

/**
 * strcpy_path - Copy a string into another, adding a path separator, and part of a user input
 * @destination: Destination string
 * @source: Source string
 * @userinput: User input string
 * Return: Pointer to the destination string
 */
char *strcpy_path(char *destination, char *source, char *userinput)
{
	int i_dest = 0;
	int i_userinput = 0;
	int i_source = 0;

	while (source[i_source])
	{
		destination[i_dest] = source[i_source];
		i_source++;
		i_dest++;
	}
	destination[i_dest] = '/';
	i_dest++;
	while (userinput[i_userinput] && iswhite(userinput[i_userinput] == -1))
	{
		i_userinput++;
	}
	while (userinput[i_userinput] && iswhite(userinput[i_userinput]) == 0)
	{
		destination[i_dest] = userinput[i_userinput];
		i_userinput++;
		i_dest++;
	}
	destination[i_dest] = '\0';
	return destination;
}

/**
 * strdup_path - Duplicate a string while adding a path separator and part of a user input
 * @str: The string to duplicate
 * @user_input: User input string
 * Return: Pointer to the duplicated string
 */
char *strdup_path(char *str, char *user_input)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return NULL;
	}

	size = _strlen(str) + strlen_forpath(user_input) + 2; /* +1 only not +2 */
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		free(dupl);
		return NULL;
	}
	strcpy_path(dupl, str, user_input);
	return dupl;
}

/**
 * remove_PATH - Remove "PATH=" from an environment variable
 * @firsttoken: The environment variable
 * Return: Pointer to the modified string
 */
char *remove_PATH(char *firsttoken)
{
	return (firsttoken + 5);
}

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
