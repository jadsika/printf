#include "main.h"
/**
 * _form_print - Prints an argument
 * @form: Formatted string
 * @list: List of arguments
 * @i: i.
 * @buffer: Buffer array that handles print.
 * @flags: Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int _form_print(const char *form, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
  int d, un_len = 0, printed_chars = -1;
  form_at form_types[] = {
			  {'c', _print_c}, {'s', _print_s}, {'%', _print_p},
			  {'i', _print_integar}, {'d', _print_integar}, {'b', _print_b},
			  {'u', _print_u}, {'o', _print_o}, {'x', _print_hexaD},
			  {'X', _print_hexaU}, {'p', _print_pnter}, {'S', _print_np},
			  {'r', _print_rev}, {'R', _print_rot}, {'\0', NULL}
  };
  for (d = 0; form_types[d].form != '\0'; d++)
    if (form[*i] == form_types[d].form)
      return (form_types[d].ff(list, buffer, flags, width, precision, size));

  if (form_types[d].form == '\0')
    {
      if (form[*i] == '\0')
	return (-1);
      un_len += write(1, "%%", 1);
      if (form[*i - 1] == ' ')
	un_len += write(1, " ", 1);
      else if (width)
	{
	  --(*i);
	  while (form[*i] != ' ' && form[*i] != '%')
	    --(*i);
	  if (form[*i] == ' ')
	    --(*i);
	  return (1);
	}
      un_len += write(1, &form[*i], 1);
      return (un_len);
    }
}
