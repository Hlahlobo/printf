#include "main.h"
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format
 * Return: Charecters
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			i++;
			printed = hanlde_print(format, &i, list, buffer,
					flags, width, precision, size);

			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buffer);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of a buffer
 * @buffer: array
 * @buff_ind: Index
 * Return: Nothing
 */

void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buff_ind > 0)
		write(1, buffer[0], *buff_ind);

	*buff_ind = 0;
}
