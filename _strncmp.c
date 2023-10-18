#include "main.h"

/*@n : size of str_known_size*/

int _strncmp(char *str_unknown_size, char *str_known_size, int n)
{
    int i = 0;

    if(!str_known_size || !str_unknown_size)
    {
        perror("_STRNCMP ERROR");
        return (1);
    }
    if(strlen(str_unknown_size) < n)
    {
        perror("_STRNCMP n > str_unkonw_size");
        return (1);
    }
    while(str_unknown_size[i] != '\0' && n > 0)
    {
        n--;
        if(str_known_size[i] != str_unknown_size[i])
        {
            return(-1); /*difference*/
        }
        i++;
    }
    return (0); /*match*/
}
/*
    for(i = 0; n > 0 && str_unknown_size[i] != NULL && str_known_size[i] != NULL ; n--)
    {
        if (str_unknown_size[i] != str_known_size[i])
        {
            return(-1);
        }
    }
    return(0);/*equal*/

