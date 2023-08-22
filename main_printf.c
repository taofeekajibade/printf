#include "main.h"
/**
 * _printf - prints formatted output according to the stated specifiers.
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total = 0;
	int i;
	va_list list;

	va_start(list, format);

	if (!format)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				total = cp_str(format, list, i, total);
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				total = integers(format, list, i, total);
			else if (format[i] == 'o' || format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
				total = octa_hex(format, list, i, total);
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
