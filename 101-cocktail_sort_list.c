#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the list.
 * @left: The left node to be swapped.
 * @right: The right node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integer
 * using the Cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
