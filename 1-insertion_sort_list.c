#include "sort.h"

/**
 * insertion_sort_list - insertion sorting doubly linked list
 * @list: the list to sort ascending
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *nnode, *pnode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	temp = (*list)->next;
	nnode = temp->next;
	while (temp)
	{
		if (temp->n < temp->prev->n)
		{
			pnode = temp->prev;
			while (pnode && (pnode->n > temp->n))
			{
				if (!pnode->prev)
				{
					pnode->prev = temp;
					temp->prev->next = temp->next;
					if (temp->next)
						temp->next->prev = temp->prev;
					temp->next = pnode;
					temp->prev = NULL;
					*list = temp;
				} else
				{
					temp->prev->next = temp->next;
					if (temp->next)
						temp->next->prev = temp->prev;
					pnode->prev->next = temp;
					temp->prev = pnode->prev;
					pnode->prev = temp;
					temp->next = pnode;
				}
				print_list(*list);
				pnode = temp->prev;
			}
		}
		temp = nnode;
		temp ? (nnode = temp->next) : (nnode = NULL);
	}
}
