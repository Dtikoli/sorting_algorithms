#include "sort.h"

/**
 * merge_subarray - Sorts a subarray of integers.
 * @subarr: Subarray of an array of integers.
 * @ptr: Pointer to the sorted subarray.
 * @front: Front index of the array.
 * @mid: Middle index of the array.
 * @back: Back index of the array.
 */
void merge_subarray(int *subarr, int *ptr, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		ptr[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		ptr[k++] = subarr[i];
	for (; j < back; j++)
		ptr[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = ptr[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * sort_recursive - A recursive Implementation of the merge sort algorithm.
 * @subarray: Subarray of an array of integers to sort.
 * @ptr: Pointer to the sorted array.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 */
void sort_recursive(int *subarray, int *ptr, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		sort_recursive(subarray, ptr, front, mid);
		sort_recursive(subarray, ptr, mid, back);
		merge_subarray(subarray, ptr, front, mid, back);
	}
}

/**
 * merge_sort - Implements the merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *ptr;

	if (!array || size < 2)
		return;

	ptr = malloc(sizeof(int) * size);
	if (!ptr)
		return;

	sort_recursive(array, ptr, 0, size);

	free(ptr);
}
