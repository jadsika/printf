#include "main.h"

/**
 * fetch_precision - Extracts precision for printing
 * @format: Formatted string
 * @e: Pointer to the current position
 * @list: List of arguments
 *
 * Return: Precision
 */
int fetch_precision(const char *format, int *e, va_list list)
{
	int cur_f = *e + 1;
	int precision = -1;

	if (format[cur_f] != '.')
		return (precision);

	precision = 0;

	for (cur_f += 1; format[cur_f] != '\0'; cur_f++)
	{
		if (c_digit(format[cur_f]))
		{
			precision *= 10;
			precision += format[cur_f] - '0';
		}
		else if (format[cur_f] == '*')
		{
			cur_f++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*e = cur_f - 1;

	return (precision);
}
