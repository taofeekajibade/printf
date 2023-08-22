#include "main.h"
/**
 * _printf - prints formatted output according to the stated specifiers.
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int total = 0, width = 0;
    int i, j, k, d;
    unsigned int u;
    void *ptr;
    char *str;
    char c, int_str[20];
    va_list list;
    bool plus = false, space = false, hash = false;

    va_start(list, format);

    if (!format)
        return (-1);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0' || format[i] == '-')
            {
                if (format[i] == '+')
                    plus = true;
                else if (format[i] == ' ')
                    space = true;
                else if (format[i] == '#')
                    hash = true;
                /*else if (format[i] == '0')
                    zero = true;
		else if (format[i] == 'l')
			l_mod = true;
		else if (format[i] == 'h')
			h_mod = true;
                else if (format[i] == '-')
                    minus = true;*/
                i++;
            }
            while (format[i] >= '0' && format[i] <= '9')
            {
                width = width * 10 + (format[i] - '0');
                i++;
            }
            /*if (format[i] == 'l')
            {
                l_mod = true;
                i++;
            }
            else if (format[i] == 'h')
            {
                h_mod = true;
                i++;
            }*/
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
            else if (format[i] == 'S')
            {
                str = va_arg(list, char *);
                for (j = 0; str[j] != '\0'; j++)
                {
                    if ((str[j] > 0 && str[j] < 32) || str[j] >= 127)
                    {
                        sprintf(int_str, "\\x%02X", str[j]);
                        for (k = 0; int_str[k] != '\0'; k++)
                        {
                            _putchar(int_str[k]);
                            total++;
                        }
                    }
                    else
                    {
                        _putchar(str[j]);
                        total++;
                    }
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                total++;
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                d = va_arg(list, int);
                if (d < 0)
                {
                    _putchar('-');
                    d = -d;
                    total++;
                }
                else if (plus)
                {
                    _putchar('+');
                    total++;
                }
                else if (space)
                {
                    _putchar(' ');
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
            else if (format[i] == 'o')
            {
                u = va_arg(list, unsigned int);
                if (hash && u != 0)
                {
                    _putchar('0');
                    total++;
                }
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
                if (hash && u != 0)
                {
                    _putchar('0');
                    _putchar('x');
                    total += 2;
                }
                if (format[i] == 'x')
                    sprintf(int_str, "%x", u);
                else
                    sprintf(int_str, "%X", u);
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
            else if (format[i] == 'b')
            {
                u = va_arg(list, unsigned int);
                k = 0;
                while (u > 0)
                {
                    int_str[k++] = (u & 1) + '0';
                    u >>= 1;
                }
                while (--k >= 0)
                {
                    _putchar(int_str[k]);
                    total++;
                }
            }
        }
        else
        {
            _putchar(format[i]);
            total++;
        }
    }
    va_end(list);
    return(total);
}
