#include "sort.h"

/**
 * swap_int - A function that swaps two integers in an array
 * @k: The first integer to be swapped
 * @l: The second integer to be swapped
 */
void swap_int(int *k, int *l)
{
	int tmp;

	tmp = *k;
	*k = *l;
	*l = tmp;
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
	int *mini;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (b = a + 1; b < size; b++)
			mini = (array[b] < *mini) ? (array + b) : mini;

		if ((array + b) != mini)
		{
			swap_int(array + a, mini);
			print_array(array, size);
		}
	}
}
