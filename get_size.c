#include "main.h"

/**
 * get_size - it calculates the size to cast the argument
 * @format: the formatted string in which to print the arguments
 * @index: the list of arguments to be printed
 * Return: the precision
 */
int get_size(const char *format, int *index)
{
	int curr_index = *index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
		size = S_LONG;
	else if (format[curr_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = curr_index - 1;
	else
		*index = curr_index;

	return (size);
}
