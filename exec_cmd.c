#include "main.h"

int execute_path(char **input_array, char **argv, char *path)
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
        if(execve(path, input_array, environ) == -1)
        {
            perror(argv[0]);
            free_array(input_array); //HWC
            //input_array = NULL;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        //free_array(input_array); //HWC
        //input_array = NULL;
    }
    return (WEXITSTATUS(status));
}

int access_ok(char **paths)
{
    int i = 0;

    if(!paths)
    {
        perror("NO PATH");
        return(-1);
    }

    while(paths[i])
    {
        if(access(paths[i], X_OK) == 0)
        {
            return(i); /*to access it in array*/
        }
        i++;
    }
    return(-2);
}
int exec_cmd(char **paths, char **argv,char **tokenized_input)
{
    pid_t pid;
    int status;
    int index;

    index = access_ok(paths);

    if(index >= 0)
    {
        execute_path(tokenized_input, argv, paths[index]);
    }
    else if(index < 0)
    {
        return(-1);
    }

    return(0); /*success*/
}
/*
extern char **environ;

int execute(char **input_array, char **argv)
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
        if(execve(input_array[0], input_array, environ) == -1)
        {
            perror(argv[0]);
            free_array(input_array); //HWC
            //input_array = NULL;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        //free_array(input_array); //HWC
        //input_array = NULL;
    }
    return (WEXITSTATUS(status));
}
*/