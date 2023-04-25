#include "main.h"

/**
 * _printstr - prints a reverse string.
 * @s: is a pointer to a char array
 * Return: Returns the reverse pointer
**/

void _printstr(char *s)
{

if (*s == 0)
	return;

s++;
_printstr(s);
s--;
_putchar(*s);

}
