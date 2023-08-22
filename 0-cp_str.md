#include "main.h"
/**
 * cp_str - handles character, string and percentage
 * return: total
 */
int cp_str(const char *format, va_list list, int i, int total)
{
    char c, *str;
    int j;

    if (format[i] == 'c')
    {
        c = va_arg(list, int);
        _putchar(c);
        total++;
    }
    else if (format[i] == 's')
    {
        str = va_arg(list, char *);
        for (j = 0; str[j] != '\0'; j++)
        {
            _putchar(str[j]);
            total++;
        }
    }
    else if (format[i] == '%')
    {
        _putchar('%');
        total++;
    }
    return total;
}
