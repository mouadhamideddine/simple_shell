#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
/**
 * 
*/
extern char **environ;

int execute(char **token_array, char **argv)
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
        if(execve(token_array[0], token_array, environ) == -1)
        {
            perror(argv[0]);
            free_array(token_array); //HWC
            //token_array = NULL;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        //free_array(token_array); //HWC
        //token_array = NULL;
    }
    return (WEXITSTATUS(status));
}
