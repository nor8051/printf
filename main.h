#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define BUF_FLUSH -1
#define FLAGS_INIT {0, 0, 0, 0, 0}


typedef struct flags
{
	unsigned int plusf;
	unsigned int spacef;
	unsigned int hashtagf;
	unsigned int hmod;
	unsigned int lmod;
} flags_t;
typedef struct specifier
{
	char spec;
	int (*f)(va_list ap, flags_t *f);
} specType;

int _puts(char *str);
int _putchar(int c);

/* _prinf.c module */
int _printf(const char *format, ...);

/* get_print.c module */
int (*getPrint(char s))(va_list, flags_t *);
int getFlags(char s, flags_t *f);
int getModifier(char s, flags_t *f);

/* printAlpha.c module */
int printStr(va_list ap, flags_t *f);
int printChar(va_list ap, flags_t *f);
int printModulo(va_list ap, flags_t *f);

/* printNum.c module */
int printInt(va_list ap, flags_t *f);
int printUnsigned(va_list ap, flags_t *f);
char *convert(unsigned long int num, int base, int lowercase);

/* printBases.c module */
int printBinary(va_list ap, flags_t *f);
int printHexL(va_list ap, flags_t *f);
int printHexU(va_list ap, flags_t *f);
int printOctal(va_list ap, flags_t *f);
int printAddr(va_list ap, flags_t *f);

/* printAlpha_2.c module */
int printReverse(va_list ap, flags_t *f);
int printRot13(va_list ap, flags_t *f);
int printS(va_list ap, flags_t *f);
#endif
