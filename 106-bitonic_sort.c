#include "sort.h"
#include <stdio.h>

/**
 * bitcompare - A function that compares and swaps
 * with bitcompare algorithm
 * @array: An array to be sorted in bitcompare
 * @i: The size of the array
 * @j: An exponent from the parameter
 * @dir: The direction that is to be compared
 */
void bitcompare(int *array, int i, int j, int dir)
{
	int swap_pi;

	if (dir == (array[i] > array[j]))
	{
		swap_pi = array[j];
		array[j] = array[i];
		array[i] = swap_pi;
	}
}

/**
 * bitmerge - A function that merges 2 subarrays
 * with bitmerge algorthm.
 * @array: The array to be sorted in bitcompare
 * @low: The size of the array
 * @cnt: An exponent from the parameter
 * @dir: The direction that is to be merged
 */
void bitmerge(int *array, int low, int cnt, int dir)
{
	int a, b;

	if (cnt < 2)
		return;

	b = cnt / 2;

	for (a = low; a < low + b; a++)
		bitcompare(array, a, a + b, dir);
	bitmerge(array, low, b, dir);
	bitmerge(array, low + b, b, dir);
}

/**
 * bitsort - A function that implements the bitonic sort algorithm
 * @array: An array to be sorted in bitsort
 * @low: The size of the array
 * @cnt: An exponent from the parameter
 * @dir: The direction of sorting
 * @size: The size of the array
 */
void bitsort(int *array, int low, int cnt, int dir, size_t size)
{
	int a;
	char *str;

	if (cnt < 2)
		return;

	a = cnt / 2;

	if (dir == 1)
		str = "UP";
	else
		str = "DOWN";

	printf("Merging [%i/%lu] (%s):\n", cnt, size, str);
	print_array(array, cnt);

	bitsort(array, low, a, 1, size);
	bitsort(array, low + a, a, 0, size);
	bitmerge(array, low, cnt, dir);

	printf("Result [%i/%lu] (%s):\n", cnt, size, str);
	print_array(array, cnt);
}

/**
 * bitonic_sort - A function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: An array to be sorted in bitonic_sort
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitsort(array, 0, size, 1, size);
}
