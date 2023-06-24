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
	int min, idx;
	int i;

	min = array[start_index];
	idx = start_index;
	for (i = start_index; i < (int)size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			idx = i;
		}
	}
	if (idx == start_index)
		return (-1);
	return (idx);
}

/**
 * selection_sort - Implements the selection sort algrithm
 * @array: Array to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int min, tmp;

	for (i = 0; i < (int)size; i++)
	{
		min = find_min(array, size, i);
		if (min != -1)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
