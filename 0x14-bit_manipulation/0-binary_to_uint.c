#include "main.h"

/**
 * binary_to_uint - converts a binary num to an
 * unsigned int.
 * @b: binary.
 * This code is CONSTRUCTED  by KENNY
 * wishing myself a goodluck
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ui;
	int len, base_two;

	if (!b)
		return (0);

	ui = 0;

	for (len = 0; b[len] != '\0'; len = len + 1)
		;

	for (len = len - 1, base_two = 1; len >= 0; len--, base_two = base_two * 2)
	{
		if (b[len] != '0' && b[len] != '1')
		{
			return (0);
		}

		if (b[len] & 1)
		{
			ui = ui +  base_two;
		}
	}

	return (ui);
}
