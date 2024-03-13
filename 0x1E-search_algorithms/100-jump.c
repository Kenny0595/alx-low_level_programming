#include <math.h>
#include "search_algos.h"
#include <stdio.h>

/**
 * lin_search - searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: a pointer to the first element of the array to search in
 * @beg: the index of the beggening of the subarray to be searched
 * @end: the index of the end of the subarray to be searched
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 * or -1 If value is not present in array or if array is NULL
*/

int lin_search(int *array, int beg, int end, int value)
{
	int i;

	for (i = beg; i <= (int) end; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}


/**
 * jump_search - searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 * or -1 If value is not present in array or if array is NULL
*/

int jump_search(int *array, size_t size, int value)
{
	int i, step;

	if (!array)
	{
		return (-1);
	}
	step = (int) sqrt((double) size);
	for (i = 0; i < (int) size; i += step)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (i + step >= (int) size)
		{
			printf("Value found between indexes [%d] and [%d]\n", i, i + step);
			return (lin_search(array, i, (int) size - 1, value));
		}
		if (value >= array[i] && value <= array[i + step])
		{
			printf("Value found between indexes [%d] and [%d]\n", i, i + step);
			return (lin_search(array, i, i + step, value));
		}
	}
	return (-1);
}
