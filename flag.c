#include "main.h"

/**
 * fetch_flags - Extract and return active flags
 * @format: Formatted strings
 * @e: Pointer to the current position
 *
 * Return: Flags
 */
int fetch_flags(const char *format, int *e)
{
	int i, cur_f;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {
		F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0
	};

	for (cur_f = *e + 1; format[cur_f] != '\0'; cur_f++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
		{
			if (format[cur_f] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}
		}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*e = cur_f - 1;

	return (flags);
}
