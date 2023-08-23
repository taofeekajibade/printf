#include "main.h"
/**
 * _printf - prints characters and strings
 * @format: argument to the function
 * Return: total characters
 */

int _printf(const char *format, ...)
{
	int total = 0, d, i, len, precision, width;
	unsigned int u;
	char c;
	/*char int_str[20];*/
	char *str;
	/*void *ptr;*/
	bool plus = false, space = false, hash = false, minus = false;
	/* bool long_mod = false, short_mod = false;*/
	va_list list;

	va_start(list, format);

	while (*format)
	{
		if (*format == '%') 
		{
			format++;

			/* Handle flags */
			while (*format == '+' || *format == ' ' || *format == '#' || *format == '0' || *format == '-')
			{
				if (*format == '+') plus = true;
				else if (*format == ' ') space = true;
				else if (*format == '#') hash = true;
				else if (*format == '-') minus = true;
				format++;
			}
			/* Handle width*/
			width = 0;
			while (*format >= '0' && *format <= '9')
			{
				width = width * 10 + (*format - '0');
				format++;
			}
			/* Handle precision*/
			precision = -1;
			if (*format == '.')
			{
				format++;
				precision = 0;
				while (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
					format++;
				}
			}
			/* Handle length modifiers (l and h)*/
			/* if (*format == 'l')
			   {
			   long_mod = true;
			   format++;
			   }
			   else if (*format == 'h')
			   {
			   short_mod = true;
			   format++;
			   }*/

			/* Handle specifiers */
			if (*format == 'c')
			{
				if (minus)
				{
					c = va_arg(list, int);
					_putchar(c);
					total++;
					for (i = 1; i < width; i++)
					{
						_putchar(' ');
						total++;
					}
				}
				else
				{
					c = va_arg(list, int);
					_putchar(c);
					total++;
				}
			}
			else if (*format == 's')
			{
				if (minus)
				{
					str = va_arg(list, char *);
					len = strlen(str);
					print_str(str, &total);
					for (i = len; i < width; i++)
					{
						_putchar(' ');
						total++;
					}
				}
				else 
				{
					str = va_arg(list, char *);
					print_str(str, &total);
				}
			}
			else if (*format == 'r')
			{
				if (minus)
				{
					str = va_arg(list, char *);
					print_str(str, &total);
					len = strlen(str);
					for (i = len -1; i >= 0; i--)
					{
						_putchar(str[i]);
						total++;
					}
					for (i = len; i < width; i++)
					{
						_putchar(' ');
						total++;
					}
				}
				else
				{
					str = va_arg(list, char *);
					for (i = strlen(str) - 1; i >= 0;i--)
					{
						_putchar(str[i]);
						total++;
					}
				}

				if (precision >= 0)
				{
					for (i = 0; str[i] && i < precision; i++)
					{
						_putchar(str[i]);
						total++;
					}
				}
				else
				{
					print_str(str, &total);
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(list, int);
				if (d < 0)
				{
					_putchar('-');
					total++;
					d = -d;
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
				print_int(d, &total);
			}
			else if (*format == 'u')
			{
				u = va_arg(list, unsigned int);
				print_int(u, &total);
			}
			else if (*format == 'o')
			{
				u = va_arg(list, unsigned int);
				if (hash && u != 0)
				{
					_putchar('0');
					total++;
				}
				print_str("0", &total);  /*To handle the case of '0' precision*/
				print_hex(u, &total, false);
			}
			else if (*format == 'x' || *format == 'X')
			{
				u = va_arg(list, unsigned int);
				if (hash && u != 0)
				{
					_putchar('0');
					_putchar(*format);
					total += 2;
				}
				print_hex(u, &total, *format == 'X');
			}
			else if (*format == 'b')
			{
				u = va_arg(list, unsigned int);
				print_binary(u, &total);
			}
			/*else if (format[i] == 'p')
			{
				ptr = va_arg(list, void *);
				sprintf(int_str, "%p", (unsigned long)ptr);
				for (j = 0; int_str[j] != '\0'; j++)
				{
					_putchar(str[j]);
					total++;
				}
			}*/
			else if (*format == '%')
			{
				_putchar('%');
				total++;
			}
		}
		else
		{
			_putchar(*format);
			total++;
		}
		format++;
	}
	va_end(list);
	return total;
}
