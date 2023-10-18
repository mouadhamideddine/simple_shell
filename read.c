#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

char *readline(void)
{
    //printf("here");
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
    }
    //printf("dollar write");
    n = getline(&line, &len, stdin);
    //printf("line from getline %s", line);
    if (n == -1)
    {
        free(line);
        return(NULL);
    }
    //printf("%s", line);
    //printf("readline finished");
    return(line);
}
