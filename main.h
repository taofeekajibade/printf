#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_str(const char *str, int *total);
void print_int(int num, int *total);
void print_hex(unsigned int num, int *total, bool use_uppercase);
void print_binary(unsigned int num, int *total);


#endif
