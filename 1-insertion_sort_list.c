#include "sort.h"

/**
 * swp_nodes - Swap 2 nodes in a listint_t doubly linked list.
 * @h: pointer to the head of the doubly linked list.
 * @n1: pointer to first node to swap.
 * @n2: second node to swap.
 */
void swp_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: pointer to the head of a doubly-linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *in, *t;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = t)
	{
		t = i->next;
		in = i->prev;
		while (in != NULL && i->n < in->n)
		{
			swp_nodes(list, &in, i);
			print_list((const listint_t *)*list);
		}
	}
}

