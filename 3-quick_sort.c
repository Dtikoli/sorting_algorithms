#include "sort.h"

/**
 * swap - swaps two numbers
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
 * @size: size of array (size_t)
 * Return: Index of the pivot
 */
int _split(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i, j = low - 1;

	for (i = low; i <= high; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	return (j);
}

/**
 * _qsort - Sorts an array recursively using Lomoto's qsort algorithm
 * @array: Array to be sorted
 * @low: Lowest value of the array
 * @high: Highest value of the array
 * @size: Size of the trray
 */
void _qsort(int *array, int low, int high, size_t size)
{
	int idx;

	if (low < high)
	{
		idx = _split(array, low, high, size);
		_qsort(array, low, idx - 1, size);
		_qsort(array, idx + 1, high, size);
	}
}

/**
 * quick_sort - Implements the quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_qsort(array, 0, size - 1, size);
}
