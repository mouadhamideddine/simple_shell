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