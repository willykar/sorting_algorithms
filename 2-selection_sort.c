#include "sort.h"

void swap_int(int *k, int *l);

/**
 * swap_ints - A function that swaps two integers in an array
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - a function that sorts an array
 * of integers in ascending order using the
 * Selection sort algorithm
 * @array: array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
