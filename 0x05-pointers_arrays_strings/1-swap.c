#include "main.h"
/**
 *swap_int - swap value of two ints.
 *@a: pointer to one int.
 *@b: pointer to second int.
 *Return: void.
 *This code is written by Karintoks.
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}