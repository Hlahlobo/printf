#include "main.h"


/***************************** PRINT UNSIGNED ***************************/
/**
 * print_unsigned - print_unsigned
 * @types: types
 * @buffer: buff
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Unsigned
 */

int print_unsigned(va_list types, char buffer[]
		int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_args(types unsigned long int);

	num = convert_size_ unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, 
			flags, width, precision, size));
}

/***************************** PRINT INT *************************/
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

int print_octal(va_list type, char buffer[],
		 int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_args(types unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);

	num = convert_num_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;
	
	return (write_unsgnd(0, i, buffer,
				 flags, width, precision, size));

}


/***************************** PRINT HEX UPPER ***************************/

/**
 * print_hexa_upper - Print int
 * @types: Type
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Printed
 */

int print_hexa_upper(va_list type, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_haxa(types, "0123456789ABCDEF", buffer, flags,
				'x', width, precision, size));
}

/***************************** PRINT HEX UPPER OR LOWER *********************/
/**
 * print_hexa_upper - Print int
 * @types: Type
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * @map_to: Map
 * @flag_ch: Other flag
 * Return: Printed
 */

int print_int(va_list type, char buffer[],
		int flags, char flags_ch, int width, int precision, int size)
{
	unsigned long int num = va_args(types unsigned long int);
	unsigned long int int_num = num;

	int i = BUFF_SIZE - 2;


}
