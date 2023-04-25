#include <stdio.h>
#include "main.h"
/**
 * _tobinoct - Converts usigned integer to binary.
 * @n: input number.
 * @m: counter.
 * @sys: system
 * Return: Returns a binary number.
**/
int _tobinoct(unsigned int n, int m, unsigned int sys)
{
	if (n < sys)
	{
		_putchar(n + '0');
		return (1);
	}
	m = _tobinoct(n / sys, m + 1, sys) + 1;
	_putchar(n % sys + '0');
	return (m);
}
