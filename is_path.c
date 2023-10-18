#include "main.h"
#include <stdio.h>

int is_path(char *input)
{
    int i = 0;
    //write(STDOUT_FILENO, "f", 1);
    if (!input)
    {
        return (-1);/*invalid input*/
    }
    while(input[i])
    {
        //printf("%s",input[i]);
        if(input[i] == '\\' || (input[i] == '/'))
        {
            return (1); /*path directory adress*/
        }
        i++;
    }
    return(0); /*not path example : afafafaef*/
}