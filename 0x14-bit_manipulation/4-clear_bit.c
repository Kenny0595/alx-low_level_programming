#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to the num to change
 * @index: index of the bit to clear
 * This code is written by KENNY
 * wishing myself a goodluck
 * Return: 1 if successful but if otherwise return -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
