#include "main.h"
/**
 * _printf - prints formatted output according to the stated specifiers.
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total = 0;
	int i, j, d;
	unsigned int u;
	void *ptr;
	char *str;
	char c, int_str[20];
	va_list list;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(list, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
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
			else if (format[i] == 'd' || format[i] == 'i')
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
			else if (format[i] == 'o')
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
		}
		else
		{
			_putchar(format[i]);
			total++;
		}
	}
	va_end(list);
	return (total);
}
