#include "main.h"

char** tokenize_path(char *fullpath, char*user_input)
{
    char **tokenized_fullpath = NULL;
    char *path_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;

    if (fullpath == NULL)
    {
        return(NULL);
    }
    
    path_copy = _strdup(fullpath);
    token = strtok(path_copy, ":");
    while(token != NULL)
    {
        count_token++;
        token = strtok(NULL, ":");
    }
    free(path_copy);
    path_copy = NULL;
    tokenized_fullpath = malloc(sizeof(char *) * (count_token + 1)); /* for NULL*/
    if (tokenized_fullpath == NULL)
    {
        /*free(fullpath); reason it's environ[i]*/
        return(NULL);
    }
    token = strtok(fullpath, ":");
    while (token != NULL)
    {
        tokenized_fullpath[i] = strdup_path(token, user_input);
        token = strtok(NULL, ":");
        i++;
    }
    tokenized_fullpath[i] = NULL;
    /*free(fullpath); reason it's environ[i]*/
    /*fullpath = NULL; reason it's environ[i]*/
    return (tokenized_fullpath); /*a tokenized full path ready for access*/
} 
/**
 * strdup_path - strdup
 * @str : string
 * Return: Pointer to char
 */
char *strdup_path(char *str, char *user_input)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + _strlen(user_input) + 2;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
        free(dupl);
		return (NULL);
	}
	strcpy_path(dupl, str, user_input);
	return (dupl);
}
/**
 * strcpy_path - copy string
 * @dest : destination
 * @src : source
 * Return: Pointer to str
 */
char *strcpy_path(char *dest, char *src, char *user_input)
{
	int l = 0;
	int x = 0;
    int i = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '/';
    l++;
    while(user_input[i])
    {
        dest[l] = user_input[i];
    }
    dest[l] = '\0';
	return (dest);
}
int is_path(char *input)
{
    int i = 0;
    //printf("started is_path");
    if (!input)
    {
        return (-1);/*invalid input*/
    }
    while(input[i])
    {
        //printf("inside while is_path");
        if(input[i] == '\\' || (input[i] == '/'))
        {
            printf("if(input[i] == '\\' || (input[i] == '/'))");
            return (1); /*path*/
        }
        i++;
    }
    printf("not path");
    return(0); /*not path*/
}
char *get_path(void)
{
    char path_indic[] = "PATH=";
    int i = 0;
    printf("getpath");
    while(environ[i])
    {
        if(_strncmp(environ[i],path_indic, 5) == 0)
        {
            return(environ[i]);
        }
        i++;
    }
    return(NULL);
}
