#include "sort.h"

/*
 *  bubble_sort - A finction that sorts an array of integers
 *  in ascending order using Bubble sort
 *  array: Array to sort
 *  size: The size of the array
 *  Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i;

	if (array == NULL || size < 2)
		return;
	while (swapped)
	{
		swapped = 0;

		for(i = 0; i < size; i++)
		{
			if(array[i] > array[i + 1])
			{
				swapped = 1;
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
