#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory
 * @old_size: Size of the old memory block
 * @new_size: Size of the new memory block
 * Return: Pointer to the newly allocated memory
 */
void *_realloc(void *ptr, int old_size, int new_size)
{
	char *ptr1;
	char *old_ptr;
	int i;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
	{
		return (malloc(new_size));
	}
	ptr1 = malloc(new_size);
	if (!ptr1)
	{
		return (NULL);
	}

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr1[i] = old_ptr[i];
	}
	else
	{
		for (i = 0; i < old_size; i++)
			ptr1[i] = old_ptr[i];
	}

	free(ptr);
	return (ptr1);
}

