#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



int _putchar(char c);
int _printf(const char *format, ...);
int cp_str(const char *format, va_list list, int i, int total);
int integers(const char *format, va_list list, int i, int total);
int octa_hex(const char *format, va_list list, int i, int total);

#endif
