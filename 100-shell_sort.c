#include "sort.h"

/**
 * shell_sort - a function that sorts an array of
 * integers in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: array to be sorted using shell_sort algorithm
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t a, b, gap_p = 1;
	int swap_pd;

	if (array == NULL || size < 2)
		return;

	while (gap_p < size / 3)
		gap_p = 3 * gap_p + 1;

	while (gap_p > 0)
	{
		for (a = gap_p; a < size; a++)
		{
			swap_pd = array[a];
			for (b = a; b >= gap_p && array[b - gap_p] > swap_pd; b -= gap_p)
			{
				array[b] = array[b - gap_p];
			}
			array[b] = swap_pd;
		}
		gap_p = (gap_p - 1) / 3;
		print_array(array, size);
	}
}
