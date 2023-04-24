#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define BUF_FLUSH -1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define FLAGS_INIT {0, 0, 0, 0, 0}
/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*kerem*/
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
/* kerem*/

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


/*kerem*/

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

#endif /* MAIN_H */
