#include "sort.h"

/**
 * node_swap - swap elements in an list
 * @head: head of list
 * @node1: first node
 * @node2: second node
 */
void node_swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	if (!node1 || !node2)
		return;

	tmp1 = node1->prev;
	tmp2 = node2->next;
	if (tmp1) /* if nodes are adjacent */
		tmp1->next = node2;
	if (tmp2)
		tmp2->prev = node1;
	node1->next = tmp2;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = tmp1;
	if (tmp1 == NULL)
		*head = node2;
}

/**
 * insertion_sort_list  - implements the insertion sort algorithm
 * @list: double pointer to the head of a linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;
	int val;

	if (!list || !(*list)->next || !*list)
		return;

	current = *list;
	while (current)
	{
		prev = current->prev;
				val = current->n;

		while (prev && prev->n > val)
		{
			node_swap(list, prev, current);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
