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
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if(wait(&status) == -1)
        {
            perror("WAIT ERROR");
            exit(EXIT_FAILURE);
        }
    }
    return (0);
}