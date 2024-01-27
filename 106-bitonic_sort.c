#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - A function that swaps two integers in an array
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
 * bitonic_merge - A function that sorts a bitonic
 * sequence inside an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * @start: The starting index of the sequence in array
 * @seq: The size of the sequence to sort
 * @flow: The direction to sort
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t a, jump = seq / 2;

	if (seq > 1)
	{
		for (a = start; a < start + jump; a++)
		{
			if ((flow == UP && array[a] > array[a + jump]) ||
			    (flow == DOWN && array[a] < array[a + jump]))
				swap_ints(array + a, array + a + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - A function that converts an array of
 * integers into a bitonic sequence
 * @array: An array of integers
 * @size: The size of the array
 * @start: The starting index of a block of the
 * building bitonic sequence
 * @seq: The size of a block
 * @flow: The direction to sort
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - A function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
