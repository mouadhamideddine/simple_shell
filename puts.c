#include "main.h"
/**
 * _puts - puts
 * @str : string
 * Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
}
