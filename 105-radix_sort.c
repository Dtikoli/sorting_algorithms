#include "sort.h"

/**
 * _sort_LSD - Sorts an array with Least Significant Digit
 * @array: Array to sort
 * @size: Size of the array
 * @lsd: Least significant digit
 */
void _sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_array[10] = {0};
	int *out_array, n, m;
	size_t i, j;

	out_array = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		count_array[(array[i] / lsd) % 10]++;

	for (m = 1; m < 10; m++)
		count_array[m] += count_array[m - 1];

	for (n = size - 1; n >= 0; n--)
	{
		out_array[count_array[(array[n] / lsd) % 10] - 1] = array[n];
		count_array[(array[n] / lsd) % 10]--;
	}

	for (j = 0; j < size; j++)
		array[j] = out_array[j];

	free(out_array);
}

/**
 * radix_sort - Implements the Radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t idx, lsd;

	if (!array || size < 2)
		return;

	max = 0;
	for (idx = 0; idx < size; idx++)
		if (array[idx] > max)
			max = array[idx];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}
