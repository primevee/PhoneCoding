#include "sort.h"

void swp_nd_ad(listint_t **l, listint_t **t, listint_t **s);
void swp_nd_bd(listint_t **l, listint_t **t, listint_t **s);
void cocktail_sort_list(listint_t **list);

/**
 * swp_nd_ad - swap a node in a listint_t doubly linked list
 * of ints with the node ahead of it.
 * @l: pointer to the head of a doubly linked list of ints.
 * @t: pointer to the tail of the doubly linked list.
 * @s: pointer to the current swapping node of the cocktail
 * shaker sort algorithm.
 */
void swp_nd_ad(listint_t **l, listint_t **t, listint_t **s)
{
	listint_t *tmp = (*s)->next;

	if ((*s)->prev != NULL)
		(*s)->prev->next = tmp;
	else
		*l = tmp;
	tmp->prev = (*s)->prev;
	(*s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *s;
	else
		*t = *s;
	(*s)->prev = tmp;
	tmp->next = *s;
	*s = tmp;
}

/**
 * swp_nd_bd - swap a node in a listint_t doubly linked list
 * of ints with the node behind it.
 * @l: pointer to the head of a doubly linked list of ints
 * @t: pointer to the tail of the doubly linked list.
 * @s: pointer to the current swapping node of the cocktail
 * shaker sort algorithm.
 */
void swp_nd_bd(listint_t **l, listint_t **t, listint_t **s)
{
	listint_t *tmp = (*s)->prev;

	if ((*s)->next != NULL)
		(*s)->next->prev = tmp;
	else
		*t = tmp;
	tmp->next = (*s)->next;
	(*s)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *s;
	else
		*l = *s;
	(*s)->next = tmp;
	tmp->prev = *s;
	*s = tmp;
}

/**
 * cocktail_sort_list - sort a doubly linked list of ints in
 * ascending order using the cocktail shaker sort algorithm
 * @list: pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t, *s;
	bool sns = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (t = *list; t->next != NULL;)
		t = t->next;

	while (sns == false)
	{
		sns = true;
		for (s = *list; s != t; s = s->next)
		{
			if (s->n > s->next->n)
			{
				swp_nd_ad(list, &t, &s);
				print_list((const listint_t *)*list);
				sns = false;
			}
		}
		for (s = s->prev; s != *list; s = s->prev)
		{
			if (s->n < s->prev->n)
			{
				swp_nd_bd(list, &t, &s);
				print_list((const listint_t *)*list);
				sns = false;
			}
		}
	}
}
