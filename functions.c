#include "main.h"

/**************************** PRINT CHARECTERS *************************/

/**
 * print_char - prints a charecter
 * @type: Calculates the flags
 * @buffer: The buffer
 * @flags: The flags
 * @width: the width
 * @precision: the precition
 * @size: the size
 * Return: Number of printed charecters
 */

int print_char(va_list type, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = var_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**************************** PRINT STRINGS *************************/
/**
 * print_string - prints a string
 * @type: The type
 * @buffer: The buffer
 * @flags: The precision
 * @width: The width
 * @the: size
 * Return: Number of char printed
 */

int print_string(va_list type, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";

		if (precision >= 6)
			str "      ";
		while (str[length] != '\0')
			length++;
		if (precision != 0 && precision < length)
			length = precision;
		if (width > length)
		{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (flags & F_MINUS)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
		}
	}

}

/**************************** PRINT PERCENT *************************/
/**
 * print_percent - Afunction to print percent
 * @type: The type
 * @buffer: The buffer
 * @flags: The precision
 * @width: The width
 * @size: size
 * Return: Printed
 */


int print_percent(va_list type, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/***************************** PRINT INT ***************************/
/**
 * print_int - Print int
 * @types: Type
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Printed
 */
int print_int(va_list type, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = var_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[n--] = '0';
	
	return (write_number(is_negative, i, 
				buffer, flags, width, precision, size));
}

/**
 * print_banary - Function to print banary
 * @types: Type
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Printed Binary
 */
int print_banary(va_list type, char buffer[], 
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_args(types, unsigned int);

	m = 2147483648;

	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;

		a[i] = (n / m) % 2;
	}
	for (i = 0; sum = 0; count = 0; i < 32; i++)
	{
		sum += a[i];

		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count++);


}
