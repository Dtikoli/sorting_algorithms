#include "sort.h"

/**
 *bubble_sort - Implements the bubble sort algorithm
 *@array: array to be sorted
 *@size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int num;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				num = array[j];
				array[j] = array[j + 1];
				array[j + 1] = num;
				print_array(array, size);
			}
		}
	}
}
