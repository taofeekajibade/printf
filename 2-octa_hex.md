#include "main.h"
/**
 * octa_hex - handles octa, hexadecimal and pointer
 * return: total
 */
int octa_hex(const char *format, va_list list, int i, int total)
{
    unsigned int u;
    void *ptr;
    char int_str[20];
    int j;

    if (format[i] == 'o')
    {
        u = va_arg(list, unsigned int);
        sprintf(int_str, "%o", u);
        for (j = 0; int_str[j] != '\0'; j++)
        {
            _putchar(int_str[j]);
            total++;
        }
    }
    else if (format[i] == 'x' || format[i] == 'X')
    {
        u = va_arg(list, unsigned int);
        if (format[i] == 'x')
            sprintf(int_str, "%x", u);
        else
            printf(int_str, "%X", u);
        for (j = 0; int_str[j] != '\0'; j++)
        {
            _putchar(int_str[j]);
            total++;
        }
    }
    else if (format[i] == 'p')
    {
        ptr = va_arg(list, void *);
        sprintf(int_str, "%p", (unsigned long)ptr);
        for (j = 0; int_str[j] != '\0'; j++)
        {
            _putchar(int_str[j]);
            total++;
        }
    }
    return total;
}
