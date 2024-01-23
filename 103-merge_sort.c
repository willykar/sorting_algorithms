#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - A function that sorts a subarray of integers
 * @subarr: A subarray of an array of integers to sort
 * @buff: A buffer to store the sorted subarray
 * @front: The front index
 * @mid: The middle index
 * @back: The back index
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - A function that implements the
 * merge sort algorithm through recursion
 * @subarr: A subarray of an array of integers to sort
 * @buff: A buffer to store the result(sorted)
 * @front: The front index of the subarray
 * @back: The back index of the subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t midd;

	if (back - front > 1)
	{
		midd = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, midd);
		merge_sort_recursive(subarr, buff, midd, back);
		merge_subarr(subarr, buff, front, midd, back);
	}
}

/**
 * merge_sort -  A function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
