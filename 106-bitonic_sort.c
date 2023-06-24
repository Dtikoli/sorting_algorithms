#include "sort.h"

/**
* index_swap - Swaps index's of an array
* @left: left or low index to swap
* @right: right or high index
*/

void index_swap(int *left, int *right)
{
	int tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

/**
* bi_merge - Bitonic merge
* @array: Array slice being merged
* @low: Lowest index
* @count: Count of slice
* @dir: Direction, ascending 1 descending 0
* @size: Size of total array for printing
*/
void bi_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
				index_swap(&array[i], &array[i + n]);
		}
		bi_merge(array, low, n, dir, size);
		bi_merge(array, low + n, n, dir, size);
	}
}

/**
* bi_sort - Bitonic recursive sort
* @array: Array to sort
* @low: Lowest index
* @count: Count of slice
* @dir: Direction, ascending 1 descending 0
* @size: Size of total array for printing
*/
void bi_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		bi_sort(array, low, n, 1, size);
		bi_sort(array, low + n, n, 0, size);
		bi_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort - Implements the bitonic sort algorithm
* @array: Array to sort
* @size: Size of array
*/
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bi_sort(array, 0, size, 1, size);
}
