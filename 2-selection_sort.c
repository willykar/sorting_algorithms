#include "sort.h"

/**
 * selection_sort - a function that sorts an array
 * of integers in ascending order using the 
 * Selection sort algorithm
 * @array: array to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, Mini_index;
	int swap_pi;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		Mini_index = a;

		for (b = a + 1; b < size; b++)
			if (array[b] < array[Mini_index])
				Mini_index = b;

		if (a != Mini_index)
		{
			swap_pi = array[Mini_index];
			array[Mini_index] = array[a];
			array[a] = swap_pi;
			print_array(array, size);
		}
	}
}
