#include "sort.h"

/**
 * swap_node - swaps nodes of a listint_t
 * @h: head of the list
 * @node1: 1st node to swap
 * @node2: 2nd node to swap
 */

void swap_node(listint_t **h, listint_t *node1, listint_t *node2)
{
	listint_t *p, *n;

	p = node1->prev;
	n = node2->next;

	if (p)
		p->next = node2;
	else
		*h = node2;

	node1->next = n;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = p;

	if (n)
		n->prev = node1;
}

/**
 * insertion_sort_list - insertion sorting doubly linked list
 * @list: the list to sort ascending
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *fornode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (fornode = (*list)->next; fornode && fornode->prev;
			fornode = fornode->next)
	{
		for (; fornode && fornode->prev && fornode->n;
				fornode = fornode->prev)
		{
			temp = fornode->prev;
			swapnode(list, temp, fornode);
			print_list(*list);
			fornode = fornode->next;
		}
	}
}
