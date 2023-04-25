#include "main.h"
/**
 * _strlen - swaps integers with pointers
 * @c: pointer to char
 * Return: Always 0
 */
int _strlen(const char *c)
{
int i = 0;

while (*(c + i) != '\0')
{
i++;
}

return (i);
}
