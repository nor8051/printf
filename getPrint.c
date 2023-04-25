#include "main.h"

/**
 * getPrint - finds function
 * @s: format string
 * Return: printed number byte
 */

int (*getPrint(char s))(va_list, flags_t *)
{
	int idx = 0;
	specType fDict[] = {
		{'c', printChar},
		{'s', printStr},
		{'d', printInt},
		{'i', printInt},
		{'o', printOctal},
		{'b', printBinary},
		{'x', printHexL},
		{'X', printHexU},
		{'u', printUnsigned},
		{'S', printS},
		{'p', printAddr},
		{'r', printReverse},
		{'R', printRot13},
		{'\0', NULL}
	};

	while (fDict[idx].spec)
	{
		if (s == fDict[idx].spec)
			return (fDict[idx].f);
		idx++;
	}
	return (NULL);
}

/**
 * getFlags - finds flag of function
 * @s: string format
 * @f: flags structure
 * Return: if flag was valid
 */
int getFlags(char s, flags_t *f)
{
	int found = 1;

	switch (s)
	{
	case '+':
		f->plusf = 1;
		break;
	case ' ':
		f->spacef = 1;
		break;
	case '#':
		f->hashtagf = 1;
		break;
	default:
		found = 0;
	}
	return (found);
}
