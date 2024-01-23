#include "sort.h"
/**
 * swapping_list - swap nodes
 * @i: first node
 * @j: second node
*/
void swapping_list(listint_t *i, listint_t *j)
{
	if (i->prev)
		i->prev->next = j;
	if (j->next)
		j->next->prev = i;
	i->next = j->next;
	j->prev = i->prev;
	i->prev = j;
	j->next = i;
}

/**
 * insertion_sort_list - a function that sorts
 * a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swapping_list(j->prev, j);
				if (j->prev == NULL)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
			{
				j = j->prev;
			}
		}
	}
}
