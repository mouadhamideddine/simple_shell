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
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while (token)
    {
        tokenized_input[i] = _strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }

    free(str_copy);
    return (tokenized_input);
} 
