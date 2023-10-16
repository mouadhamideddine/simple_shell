#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * _strlen - calculate str length
 * @s : string
 * Return: int
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}
/**
 * _strcpy - copy string
 * @dest : destination
 * @src : source
 * Return: Pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
/**
 * _strdup - strdup
 * @str : string
 * Return: Pointer to char
 */
char *_strdup(char *str)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + 1;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		return (NULL);
	}

	_strcpy(dupl, str);
	return (dupl);
}
int free_array(char **array)
{
    int i = 0;

    if (array == NULL)
    {
        return (0);
    }

    while(array[i])
    {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    free(array);
    array = NULL;
    return (0);
}

/**
 * 
*/
extern char **environ;

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
        if(execve(token_array[0], token_array, environ) == -1)
        {
            perror(argv[0]);
            free_array(token_array); //HWC
            //token_array = NULL;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        //free_array(token_array); //HWC
        //token_array = NULL;
    }
    return (WEXITSTATUS(status));
}
 


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
        return(NULL);
    }
    return(line);
}
char** tokenizeline(char* input, char* delimiters)
{
    char **tokenized_input = NULL;
    char *str_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;
    
    
    if (!input)
        return(NULL);
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while (token)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    free(str_copy), str_copy = NULL;

    tokenized_input = malloc(sizeof(char *) * (count_token + 1));
    if(!tokenized_input)
    {
        free(input);
        return(NULL);
    }
    token = strtok(input,delimiters);
    while (token)
    {
        tokenized_input[i] = _strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }
    free(input);
    input = NULL;
    tokenized_input[i] = NULL;
    //printf("tokenized 0 %s", tokenized_input[0]);
    return (tokenized_input);
}
int main(int ac, char **argv)
{
	(void)ac;
	char *input = NULL;
	size_t input_size = 0;
	char delimiters[] = {' ', '\t', '\n'};
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
			//free(input);
			return(status);
		}
		tokenized_input = tokenizeline(input, delimiters);
		//printf("tokenized_input%s", tokenized_input[0]);
		if (tokenized_input != NULL)
		{
			execute(tokenized_input, argv);
		}
		free_array(tokenized_input);
		//free(input);
		//input = NULL;
		tokenized_input = NULL;
	}
	return (status);
}



