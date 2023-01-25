#include "main.h"

/**
 * write_char - write a character to stdout
 * @str: the character to write
 * Return: 1, i.e. the number of characters(bytes) written
 */

int write_char(char str)
{
	write(1, &str, 1);
	return (1);
}

/**
 * write_format - write a variable arg to stdout using a format
 * specifier
 * @ch: the format specifier character
 * @arg: a va_list variable for fetching variable args
 * @count: a pointer to the number of bytes written to stdout
 */

void write_format(char ch, va_list arg, int *count)
{
	char *str;
	int hold;

	switch (ch)
	{
	case 's':
		str = va_arg(arg, char *);
		write_string(str, slen(str));
		*count += slen(str);
		break;
	case 'c':
		hold = va_arg(arg, int);
		*count += write_char(hold);
		break;
	case '%':
		*count += write_char('%');
		break;
	}
}

/**
 * slen - find the length of a string
 * @s: pointer to the string to print
 * Return: the length of the string in bytes, same as number of characters
 */

int slen(char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	return (1 + slen(s + 1));
}

/**
 * write_string - write an input string to stdout
 * @string: pointer to the string to write
 * @len: the lenght of the string, excluding null byte
 * Return: nothing
 */

void write_string(char *string, int len)
{
	write(1, string, len);
}
