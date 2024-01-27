#include "sort.h"
#include <sys/types.h>

/**
 * partition - A function that divides the array and
 * swap data and partitions.
 * @array: An array to be sorted in a partition argorithm
 * @low: The first index of the array
 * @high: The last index of the array
 * @size: The size of the array
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot_pi = array[low], swap_i;
	ssize_t a = low - 1, b = high + 1;

	while (1)
	{
		do {
			a++;
		} while (array[a] < pivot_pi);
		do {
			b--;
		} while (array[b] > pivot_pi);
		if (a >= b)
			return (b);
		swap_i = array[b];
		array[b] = array[a];
		array[a] = swap_i;
		print_array(array, size);
	}
}

/**
 * quicksort - A function that divides the array to
 * perform the sorting in quicksort
 * @array: The array to be sorted in quicksort algorthm
 * @low: The first index of the array
 * @high: The last index of the array
 * @size: The size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t b;

	if (low < high)
	{
		b = partition(array, low, high, size);
		quicksort(array, low, b, size);
		quicksort(array, b + 1, high, size);
	}
}

/**
 * quick_sort_hoare - A function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: The array to be sorted in quicksort algorthm
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
