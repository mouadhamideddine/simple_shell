#include <stdio.h>
#include <stdlib.h>

int free_array(char **array)
{
    int i = 0;

    if (array == NULL)
    {
        return (0);
    }

    while(array[i])
    {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    free(array);
    printf("i freed");
    return (0);
}