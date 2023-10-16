#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>  
#include "main.h"

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
