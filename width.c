#include "main.h"

/**
 * fetch_width - Extracts and calculates the width
 * @format: Formatted string
 * @e: Pointer to the current position
 * @list: List of arguments
 *
 * Return: Width
 */
int fetch_width(const char *format, int *e, va_list list)
{
  int cur_f;
  int width = 0;

  for (cur_f = *e + 1; format[cur_f] != '\0'; cur_f++)
    {
      if (c_digit(format[cur_f]))
	{
	  width *= 10;
	  width += format[cur_f] - '0';
	}
      else if (format[cur_f] == '*')
	{
	  cur_f++;
	  width = va_arg(list, int);
	  break;
	}
      else
	{
	  break;
	}
    }

  *e = cur_f - 1;
  return (width);
}
