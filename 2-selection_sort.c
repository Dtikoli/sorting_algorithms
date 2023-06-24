#include "sort.h"

/**
 * find_min - Locates the minimum from the current index in the array
 * @array: Array to be Searched
 * @size: Size of the array
 * @start_index: Starting search index
 * Return: Index of min on success, else -1.
 */
int find_min(int *array, size_t size, int start_index)
{
	int min_idx, idx, min;

	min = array[start_index];
	min_idx = start_index;
	for (idx = start_index; idx < (int) size; idx++)
	{
		if (array[idx] < min)
		{
			min = array[idx];
			min_idx = idx;
		}
	}
	if (min_idx == start_index)
		return (-1);

	return (min_idx);
}

/**
 * selection_sort - Implements the selection sort algrithm
 * @array: Array to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	int min_idx, tmp, idx;

	if (!array || size < 2)
		return;

	for (idx = 0; idx < (int) size; idx++)
	{
		min_idx = find_min(array, size, idx);
		if (min_idx != -1)
		{
			tmp = array[idx];
			array[idx] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
