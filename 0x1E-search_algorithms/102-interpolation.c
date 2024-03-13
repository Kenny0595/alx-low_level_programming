#include "search_algos.h"
#include <stdio.h>


/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located
 * or -1 If value is not present in array or if array is NULL
*/

int interpolation_search(int *array, size_t size, int value)
{
	size_t mid, l, h;

	if (!array)
		return (-1);
	l = 0;
	h = size - 1;
	do {
		mid = l +
			(size_t) (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		if (mid > size - 1)
		{
			printf("Value checked array[%ld] is out of range\n", mid);
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", mid, array[mid]);
		if (array[mid] < value)
			l = mid + 1;
		else if (array[mid] > value)
			h = mid - 1;
		else
			return ((int) mid);
	} while (array[l] < array[h] && array[l] <= value && array[h] >= value);
	if (value == array[l])
		return ((int) l);
	else
		return (-1);
}
