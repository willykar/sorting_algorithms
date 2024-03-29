#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_int - A function that swaps two integers in an array
 * @j: The first integer to swap
 * @k: The second integer to swap
 */
void swap_int(int *j, int *k)
{
	int tmp;

	tmp = *j;
	*j = *k;
	*k = tmp;
}

/**
 * max_heapify - A function that turns a binary
 * tree into a complete binary heap
 * @array: An array of integers representing a binary tree
 * @size: The size of the array
 * @base: The index of the base row of the tree
 * @root: The root node of the binary tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_int(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - A function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		max_heapify(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swap_int(array, array + a);
		print_array(array, size);
		max_heapify(array, size, a, 0);
	}
}
