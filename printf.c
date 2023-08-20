#include "main.h"
/**
 * _printf - prints formatted output
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total = 0;
	int i, j;
	char *str;
	char c;
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
