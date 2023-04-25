#include "main.h"

/**
 * print_unsigned - prints an unsigned number
 * @types: lists the arguments
 * @buffer: a buffer array to handle print
 * @flags:  it calculates active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation
 * @types: lists the arguments
 * @buffer: a buffer array to handle print
 * @flags: it calculates active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[index--] = '0';

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - this prints an unsigned number in hexadecimal notation
 * @types: lists the arguments
 * @buffer: the buffer array to handle print
 * @flags:  it calculates active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - it prints an unsigned number in upper hexadecimal
 * @types: lists the arguments
 * @buffer: the buffer array to handle print
 * @flags: it calculates active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - it prints a hexadecimal number in lower or upper
 * @types: lists the arguments
 * @map_to: the array of values to map the number to
 * @buffer: the buffer array to handle print
 * @flags: it alculates active flags
 * @flag_ch: it calculates active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * @size: the size specification
 * Return: the number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] = '0';
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
