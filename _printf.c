#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;
	int num;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					if (num < 0)
					{
						write(1, "-", 1);
						count++;
						num = -num;
					}
					count += print_number(num);
					break;
				case '%':
					write(1, format, 1);
					count++;
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * print_number - Helper function to print an integer
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	char digit;

	if (n / 10)
		count += print_number(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}
