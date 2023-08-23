#include "main.h"
/**
 * print_str - prints string
 * @str: string to be printed
 * @total: total string printed
 */
void print_str(const char *str, int *total) 
{
    while (*str)
    {
        _putchar(*str);
        (*total)++;
        str++;
    }
}
/**
 * print_int - prints integers
 * @total: total it printed
 */
void print_int(int num, int *total)
{
    char int_str[20];
    sprintf(int_str, "%d", num);
    print_str(int_str, total);
}
