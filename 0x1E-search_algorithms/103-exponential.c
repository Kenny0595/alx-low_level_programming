#include "search_algos.h"
#include <stdio.h>

/**
 * bi_search - searches for a value in an array of integers
 * using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @beg: the index of the beggening of the subarray to be searched
 * @end: the index of the end of the subarray to be searched
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 * or -1 If value is not present in array or if array is NULL
*/


int bi_search(int *array, size_t beg, size_t end, int value)
{
	size_t mid, i;

	mid = (beg + end) / 2;

	printf("Searching in array: %i", array[beg]);
	for (i = beg + 1; i <= end; i++)
	{
		printf(", %i", array[i]);
	}
	printf("\n");

	if (beg == end)
	{
		if (array[beg] == value)
			return ((int) beg);
		else
			return (-1);
	}

	if (array[mid] == value)
		return ((int) mid);
	else if (value < array[mid])
		return (bi_search(array, beg, mid - 1, value));
	else
		return (bi_search(array, mid + 1, end, value));
}



/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located
 * or -1 If value is not present in array or if array is NULL
*/

int exponential_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
	{
		return (-1);
	}
	if (array[0] == value)
		return (0);
	for (i = 1; i < size; i *= 2)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (i * 2 >= size)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, size - 1);
			return (bi_search(array, i, size - 1, value));
		}
		if (value >= array[i] && value <= array[i * 2])
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i * 2);
			return (bi_search(array, i, i * 2, value));
		}
	}
	return (-1);
}
