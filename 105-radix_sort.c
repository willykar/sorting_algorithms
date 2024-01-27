#include "sort.h"
#include <stdlib.h>

/**
 * count_sort - A function that implements count_sort algorithm
 * @array: An array to be sorted in count_sort
 * @size: The size of the array
 * @exp: An exponent from the parameter
 */

void count_sort(int *array, int size, int exp)
{
	int *output = NULL;
	int a, counter[10] = {0};

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (a = 0; a < size; a++)
		counter[(array[a] / exp) % 10]++;

	for (a = 1; a < 10; a++)
		counter[a] += counter[a - 1];

	for (a = size - 1; a >= 0; a--)
	{
		output[counter[(array[a] / exp) % 10] - 1] = array[a];
		counter[(array[a] / exp) % 10]--;
	}

	for (a = 0; a < size; a++)
		array[a] = output[a];

	free(output);
}
/**
 * radix_sort - a function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: An array to be sorted in count_sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_a, exp;
	size_t a;

	if (array == NULL || size < 2)
		return;

	max_a = array[0];
	for (a = 1; a < size; a++)
		if (array[a] > max_a)
			max_a = array[a];

	for (exp = 1; max_a / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
