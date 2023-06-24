#include "sort.h"

/**
 * list_len - Returns number of nodes in a linked list
 * @list: head pointer of list
 * Return: length of list
 */
size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * node_switch - swaps nodes in a list
 * @list: head of list
 * @ptr: pointer to node
 */
void node_switch(listint_t **list, listint_t **ptr)
{
	listint_t *node1, *node2, *node3, *node4;

	node1 = (*ptr)->prev;
	node2 = *ptr;
	node3 = (*ptr)->next;
	node4 = (*ptr)->next->next;
	node2->next = node4;
	if (node4)
		node4->prev = node2;
	node3->next = node2;
	node3->prev = node2->prev;
	if (node1)
		node1->next = node3;
	else
		*list = node3;
	node2->prev = node3;
	*ptr = node3;
}

/**
 * cocktail_sort_list - implements the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int _sort = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;

	ptr = *list;
	while (!_sort)
	{
		_sort = 1;
		while (ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				_sort = 0;
				node_switch(list, &ptr);
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		if (_sort)
			break;
		ptr = ptr->prev;
		while (ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				_sort = 0;
				ptr = ptr->prev;
				node_switch(list, &ptr);
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
	}
}
