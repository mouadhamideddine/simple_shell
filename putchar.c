#include <unistd.h>
#include "main.h"
/**
 * _putchar - putchar
 * @c : char
 * Return: void
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
