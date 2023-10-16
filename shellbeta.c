#include "main.h"
#include <stdlib.h>
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

	while (*(src + l) != '\0')
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char** tokenizeline(char* input, char* delimiters)
{
    char **tokenized_input = NULL;
    char *str_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;
    
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while(token)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    tokenized_input = malloc(sizeof(char *) * count_token);
    free(str_copy);
    str_copy = NULL;
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while (token)
    {
        tokenized_input[i] = _strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }

    free(str_copy);
    str_copy = NULL;
    return (tokenized_input);
} 
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
/**
 * 
*/
extern char **environ;

int execute(char **argv)
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
        if(execve(argv[0], argv, environ) == -1)
        {
            perror("EXECVE ERROR");
            exit(-1);
        }
    }
    else
    {
        if(wait(&status) == -1)
        {
            perror("WAIT ERROR");
            exit(-1);
        }
    }
    return (0);
}
#include <stdio.h>
#include <stdlib.h>

int free_array(char ***array_ptr)
{
    char **array = *array_ptr;
    int i = 0;
    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);
    *array_ptr = NULL;
    return(0);
}

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char delimiters[] = " ,\t,\n";
	char dollar[] = {"$ "};
	char **tokenized_input = NULL;
	char *path = NULL;
	int status = 0;

	while (1)
	{
		write(STDOUT_FILENO,dollar,2);

		if (getline(&input, &input_size, stdin) == -1)
		{
			free(input);
			return (status);
		}
		tokenized_input = tokenizeline(input, delimiters);
		/*printf("%s",tokenized_input[0]);*/
		execute(tokenized_input);
		free_array(&tokenized_input);
		tokenized_input = NULL;
	}

	free(input);
	return (0);
}
