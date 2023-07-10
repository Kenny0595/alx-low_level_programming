#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @n: pointer to the num to change
 * @index: index of the bit to set to 1
 * This code is written by KENNY
 * wishing myself a goodluck
 * Return: 1 if  sucessful if otherwise -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}