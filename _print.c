#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Print formatted output to stdout
 * @format: Format string containing format specifiers
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++; // Move past '%'
            if (*format == '\0')
                break; // Handle malformed format strings

            if (*format == 'c')
            {
                // Handle 'c' as before
            }
            else if (*format == 's')
            {
                // Handle 's' as before
            }
            else if (*format == '%')
            {
                // Handle '%' as before
            }
            else if (*format == 'd' || *format == 'i')
            {
                // Handle 'd' and 'i' as before
            }
            else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                int binary[32];
                for (int i = 0; i < 32; i++)
                {
                    binary[i] = num % 2;
                    num /= 2;
                }
                for (int i = 31; i >= 0; i--)
                {
                    write(1, binary[i] ? "1" : "0", 1);
                    count++;
                }
            }
            else
            {
                write(1, "%", 1); // Handle unsupported format specifiers as literals
                write(1, format, 1);
                count += 2;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}
