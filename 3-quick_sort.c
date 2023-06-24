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
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
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
	int i;

	if (low < high)
	{
		i = _split(array, low, high, size);
		_qsort(array, low, i - 1, size);
		_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
