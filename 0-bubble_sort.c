#include "sort.h"

/**
 * bubble_sort - A finction that sorts an array of integers
 * in ascending order using Bubble sort
 * @array: Array to sort
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a = 0, b = size;
	int tmp, sorted;

	if (array == NULL)
		return;
	for (b = size; b > 0; b--)
	{
		sorted = 0;
		for (a = 0; a < size - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				tmp = array[a];
				array[i] = array[a + 1];
				array[a + 1] = tmp;
				print_array(array, size);
				sorted = 1;
			}
		}
		if (sorted == 0)
		{
			break;
		}
	}
}
