#include "sort.h"

/**
* _heapify - recurssive heapify function
* @array: Array to sort
* @heap: Size of heap data
* @idx: Index
* @size: Size of array
*/

void _heapify(int *array, int heap, int idx, int size)
{
	int lar, left, right, tmp;

	lar = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != idx)
	{
		tmp = array[idx];
		array[idx] = array[lar];
		array[lar] = tmp;
		print_array(array, size);
		_heapify(array, heap, lar, size);
	}
}

/**
* heap_sort - Implements the heap sort algorithm
* @array: Array to sort
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	i = size / 2 - 1;

	if (!array || size < 2)
		return;

	for (; i >= 0; i--)
		_heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i > 0)
			print_array(array, size);
		_heapify(array, i, 0, size);
	}

}
