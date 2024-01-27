#include "sort.h"
#include <sys/types.h>


#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - iA function that swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot_i, above, below;

	pivot_i = array[right];
	above = left - 1;
	below = right + 1;

	while (1)
	{
		while (array[++above] < pivot_i)
			;
		while (array[--below] > pivot_i)
			;

		if (above >= below)
			break;

		swap_ints(array + above, array + below);
		print_array(array, size);

	}
	return (above);
}



/**
 * hoare_sort - A function that implements quicksort algorithm
 * @array: The array to be sorted in quicksort algorthm
 * @left: The starting index
 * @right: The ending index
 * @size: The size of the array
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part_i;

	if (right - left > 0)
	{
		part_i = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part_i - 1);
		hoare_sort(array, size, part_i, right);
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

	hoare_sort(array, 0, size - 1, size);
}
