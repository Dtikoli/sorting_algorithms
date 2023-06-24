#include "sort.h"

/**
 * swap - Swap two numbers
 * @x: int number
 * @y: int number
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * _split - Partitions an array and using pivot
 * @array: Array
 * @low: int number
 * @high: int number
 * @size: Size of array (size_t)
 * Return: Index of pivot
 */
int _split(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low;
	j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * _qsort - Sorts an array recursively using Hoare's qsort algorithm
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 */
void _qsort(int *array, int low, int high, size_t size)
{
	int idx;

	if (low < high)
	{
		idx = _split(array, low, high, size);
		if (idx > low)
			_qsort(array, low, idx, size);
		_qsort(array, idx + 1, high, size);
	}
}
/**
 * quick_sort_hoare - Implements the quick sort algorithm.
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_qsort(array, 0, size - 1, size);
}
