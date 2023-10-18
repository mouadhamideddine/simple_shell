#include "main.h"

extern char **environ;

char *get_path(void)
{
    char path_indic[] = "PATH=";
    int i = 0;
    prin

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