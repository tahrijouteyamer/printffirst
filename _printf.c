#include "main.h"

void print_buffer(char buffer[], int *bufferIndex);

/**
 * _printf - the printf function
 * @format: the format
 * Return: characters printed
 */
int _printf(const char *format, ...)
{
	int index, printed = 0, printed_chars = 0;
	int flags, width, precision, size, bufferIndex = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[bufferIndex++] = format[index];
			if (bufferIndex == BUFF_SIZE)
				print_buffer(buffer, &bufferIndex);
			/* write(1, &format[index], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &bufferIndex);
			flags = get_flags(format, &index);
			width = get_width(format, &index, list);
			precision = get_precision(format, &index, list);
			size = get_size(format, &index);
			++index;
			printed = handle_print(format, &index, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &bufferIndex);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - prints the contents of the buffer if it exists
 * @buffer: the array of characters
 * @bufferIndex: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &buffer[0], *bufferIndex);

	*bufferIndex = 0;
}
