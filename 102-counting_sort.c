#include "sort.h"

/**
 * get_max - A function that gets the maximum
 * value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: (The maximum integer in the array)
 */
int get_max(int *array, int size)
{
	int max, a;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * counting_sort - A function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, a;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (a = 0; a < (max + 1); a++)
		count[a] = 0;
	for (a = 0; a < (int)size; a++)
		count[array[a]] += 1;
	for (a = 0; a < (max + 1); a++)
		count[a] += count[a - 1];
	print_array(count, max + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorted[count[array[a]] - 1] = array[a];
		count[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(count);
}
