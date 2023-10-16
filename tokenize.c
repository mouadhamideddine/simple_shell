#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
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

    if (input == NULL)
    {
        return(NULL);
    }
    
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while(token != NULL)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    free(str_copy);
    str_copy = NULL;
    tokenized_input = malloc(sizeof(char *) * (count_token + 1)); /*removed the +1 but add again*/
    if (tokenized_input == NULL)
    {
        free(input);
        return(NULL);
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
/*
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
    printf("tokenized 0 %s", tokenized_input[0]);
    return (tokenized_input);
}
*/
//char delimiters[] = {' ', '\t', '\n', '\0'};
/*

*/
/*
char** tokenizeline(char* input, char* delimiters)
{
    char **tokenized_input = NULL;
    char *str_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;
    
    str_copy = _strdup(input);
    if (str_copy == NULL)
    {
        free(str_copy),str_copy = NULL;
        return (NULL);
    }
    token = strtok(str_copy, delimiters);
    while(token != NULL)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    if (count_token > 0)
    {
        free(str_copy);
        str_copy = NULL;
        str_copy = _strdup(input);
        if (str_copy == NULL)
        {
            free(str_copy), str_copy = NULL; return(NULL);
        }
        token = strtok(str_copy, delimiters);// this
    } 
    if (token != NULL)
    {
        tokenized_input = malloc(sizeof(char *) * (count_token)); //removed the +1 
        if (tokenized_input == NULL)
        {
            free(tokenized_input), free(str_copy), tokenized_input = NULL, str_copy = NULL;
            return (NULL);
        }
        while (token != NULL)
        {
            tokenized_input[i] = _strdup(token);
            token = strtok(NULL, delimiters);
            i++;
        }
    }

    free(str_copy);
    str_copy = NULL;
    return (tokenized_input);
} 
*/