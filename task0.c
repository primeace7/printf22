#include "main.h"

/**
 * _printf - write formated output to stdout
 * @format: the formated string to write to stdout
 * Return: the number of characters(bytes) written
 */

int _printf(const char *format, ...)
{
	int bytes_written;
	va_list arg;

	va_start(arg, format);

	for (; *format != '\0' && format != NULL; format++)
	{
		for (; *format != '%'; format++)
			bytes_written += write_char(*format);
		if (*format == '%')
		{
			format++;
			write_format(*format, arg, &bytes_written);
		}
	}
	return (bytes_written);
}
