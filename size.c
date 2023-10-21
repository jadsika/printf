#include "main.h"

/**
 * fetch_size - The size of the argument
 * @format: Formatted string
 * @e: List of arguments to be printed.
 *
 * Return: Precision.
 */
int fetch_size(const char *format, int *e)
{
int cur_f = *e + 1;
int size = 0;

if (format[cur_f] == 'l')
size = S_LONG;
else if (format[cur_f] == 'h')
size = S_SHORT;
if (size == 0)
*e = cur_f - 1;
else
*e = cur_f;

return (size);
}
