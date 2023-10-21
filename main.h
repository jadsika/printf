#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

int _printf(const char *format, ...);

int _form_print(const char *form, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/**
 * struct form - structure op
 * @form: format.
 * @ff: The function.
 */
struct form
{
	char form;
	int (*ff)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct form - Struct op
 *
 * @form: format
 * @form_at: The function
 */
typedef struct form form_at;


/* Characters & Strings */
int _print_c(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_s(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_p(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Numbers */
int _print_integar(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_b(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_u(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_o(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_hexaD(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_hexaU(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Non printable functions */
int _print_np(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Print address */
int _print_pnter(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Specifiers that need to be handled */
int fetch_flags(const char *format, int *e);
int fetch_width(const char *format, int *e, va_list list);
int fetch_precision(const char *format, int *e, va_list list);
int fetch_size(const char *format, int *i);

/* Print strings in reverse */
int _print_rev(va_list types, char buffer[],
int flags, int width, int precision, int size);

int _print_rot(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Width */
int type_char(char c, char buffer[],
int flags, int width, int precision, int size);
int type_num(int is_pos, int ind, char buffer[],
int flags, int width, int precision, int size);
int type_num2(int ind, char buffer[], int flags, int width, int prec,
int length, char padd, char extra_c);
int type_point(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int type_unsgned(int is_neg, int ind,
char buffer[], int flags, int width, int precision, int size);


int c_print(char);
int hexa_code(char, char[], int);
int c_digit(char);

long int _size_nom(long int nom, int size);
long int _size_unsignd(unsigned long int nom, int size);

#endif
