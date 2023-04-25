#include "main.h"

/**
 * is_printable - evaluates if a character is printable
 * @c: the character to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - the ascii in hexadecimal code to buffer
 * @buffer: the array of characters
 * @index: the index at which to start appending
 * @ascii_code: the ascii code
 * Return: always three
 */
int append_hexa_code(char ascii_code, char buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = map_to[ascii_code / 16];
	buffer[index] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - it verifies if a char is a digit
 * @c: the character to be evaluated
 *
 * Return: 1 if the character is a digit else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - this casts a number to the specified size
 * @num: the number to be casted
 * @size: the number indicating the type to be casted.
 *
 * Return: the casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - it casts a number to the specified size
 * @num: the umber to be casted
 * @size: the number indicating the type to be casted
 *
 * Return: the casted value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
