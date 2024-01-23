#include "sort.h"
#include <sys/types.h>

/**
 * partition_divide - A function that divides the
 * array to 2 and swaps the content in each index
 * @array: array to be sorted using quicksort
 * @low: first index opf the list
 * @high: last index of the list
 * @size: The size of the array
 */

size_t partition_divide(int *array, ssize_t low, ssize_t high, size_t size)
{
	int piv = array[high], swaped;
	ssize_t a = low - 1, b;

	for (b = low; b < high; b++)
	{
		if (array[b] < piv)
		{
			a++;
			if (a != b)
			{
				swaped = array[b];
				array[b] = array[a];
				array[a] = swaped;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[a + 1])
	{
		swaped = array[a + 1];
		array[a + 1] = array[high];
		array[high] = swaped;
		print_array(array, size);
	}
	return (a + 1);
}

/**
 * quicksort - A function that divides the array
 * to perform sorting using quicksort
 * @array: array to be sorted in quicksort.
 * @low: first index of the list or an array
 * @high: last index of the list or an array
 * @size: The size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pat;

	if (low < high)
	{
		pat = partition_divide(array, low, high, size);
		quicksort(array, low, pat - 1, size);
		quicksort(array, pat + 1, high, size);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using Quick sort algorithm
 * @array: array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
