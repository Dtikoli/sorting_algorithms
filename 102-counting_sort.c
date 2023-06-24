#include "sort.h"

/**
 * find_max - Fnds the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * Return: Maximum integer in the array.
 */
int find_max(int *array, int size)
{
	int max, idx;

	for (max = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > max)
			max = array[idx];
	}

	return (max);
}

/**
 * counting_sort - Implements the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *_sort, max, i;

	if (!array || size < 2)
		return;

	_sort = malloc(sizeof(int) * size);
	if (!_sort)
		return;

	max = find_max(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(_sort);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		_sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = _sort[i];

	free(_sort);
	free(count);
}
