#include "main.h"
/**
 * _printf - prints formatted output
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total = 0;
	int i, j, d;
	char *str;
	char c, int_str[20];
	va_list list;

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
