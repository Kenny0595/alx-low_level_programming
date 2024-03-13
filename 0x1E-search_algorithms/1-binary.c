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
 * binary_search - searches for a value in an array of integers
 * using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 * or -1 If value is not present in array or if array is NULL
*/

int binary_search(int *array, size_t size, int value)
{
	if (!array || size == 0)
	{
		return (-1);
	}
	return (bi_search(array, 0, size - 1, value));
}
