#include "sort.h"
/**
 * bubble_sort - A finction that sorts an array of integers
 * in ascending order using Bubble sort
 * @array: Array to sort
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int swap, swapped_p;
	size_t a;

	if (array == NULL || size < 2)
		return;

	while (swapped_p)
	{
		swapped_p = 0;
		for (a = 0; a < size - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swapped_p = 1;
				swap = array[a + 1];
				array[a + 1] = array[a];
				array[a] = swap;
				print_array(array, size);
			}
		}
	}
}
