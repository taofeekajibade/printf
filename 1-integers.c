#include "main.h"
/**
 * integers - handles integers of base 10
 * returns total
 */
int integers(const char *format, va_list list, int i, int total)
{
    int d, j;
    unsigned int u;
    char int_str[20];

    if (format[i] == 'd' || format[i] == 'i')
    {
        d = va_arg(list, int);
        if (d < 0)
        {
            _putchar('-');
            d = -d;
            total++;
        }
        if (d == 0)
        {
            _putchar('0');
            total++;
        }
        else
        {
            sprintf(int_str, "%d", d);
            for (j = 0; int_str[j] != '\0'; j++)
            {
                _putchar(int_str[j]);
                total++;
            }
        }
    }
    else if (format[i] == 'u')
    {
        u = va_arg(list, unsigned int);
        sprintf(int_str, "%u", u);
        for (j = 0; int_str[j] != '\0'; j++)
        {
            _putchar(int_str[j]);
            total++;
        }
    }
    return total;
}
