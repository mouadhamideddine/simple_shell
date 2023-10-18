#include "main.h"
/**
 * strcpy_path - copy string
 * @dest : destination
 * @src : source
 * Return: Pointer to str
 */
char *strcpy_path(char *dest, char *src, char *user_input)
{
	int l = 0;
	int x = 0;
    int i = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '/';
    l++;
    while(user_input[i])
    {
        dest[l] = user_input[i];
    }
    dest[l] = '\0';
	return (dest);
}