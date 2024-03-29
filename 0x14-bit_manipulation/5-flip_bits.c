#include "main.h"

/**
 * flip_bits - counts the num of bits to change
 * to get from one num to another
 * @n: 1st num
 * @m: 2nd num
 * This code is contructed by KENNY
 * wishing myself goodluck
 * Return: num of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i = i - 1)
	{
		current = exclusive >> i;
		if (current & 1)
			count = count + 1;
	}

	return (count);
}
