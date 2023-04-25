#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: 1.
 */

int _putchar(int c)
{
	static char buf[BUF_SIZE];
	static int idx;

	if (c == BUF_FLUSH || idx >= BUF_SIZE)
	{
		write(1, &buf, idx);
		idx = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[idx] = c;
		idx++;
	}
	return (1);
}

/**
 * _puts - Swaps integers and pointers.
 *
 * @str: pointer to char
 *
 * Return: Always 0.
 */

int _puts(char *str)
{
int i;
for (i = 0; str[i]; i++)
	_putchar(str[i]);
return (i);
}
