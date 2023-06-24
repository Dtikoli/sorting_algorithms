#include "deck.h"

/**
 * node_swap - Swaps node with next node
 * @deck: address of pointer to head
 * @node: node to swap
 */
void node_swap(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * deck_len - Gets the size of a card deck
 * @head: head pointer to the deck
 * Return: Size of the deck
 */
size_t deck_len(const deck_node_t *head)
{
	size_t len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}

	return (len);
}

/**
 * card_conversion - Assigns a unique numeric value to each card
 * @node: the card node to extract the value from
 * Return: a unique card id
 */
int card_conversion(deck_node_t *node)
{
	int idx;
	char *vals_array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (idx = 0; idx < 13; idx++)
	{
		if (!strcmp(node->card->value, vals_array[idx]))
			return (idx + (13 * node->card->kind));
	}

	printf("Uh-oh. Card is out of range. I'm gonna crash now.");
	exit(EXIT_FAILURE);
}

/**
 * sort_deck - Sorts the deck with cocktail shaker algorithm
 * @deck: the card deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	int _swap = 1, value1, value2;
	size_t low = 0, high, idx = 0;
	deck_node_t *tmp = *deck;

	high = deck_len(*deck) - 1;
	if (!deck || !*deck || !((*deck)->next))
		return;
	while (_swap)
	{
		_swap = 0;
		for (; idx < high; idx++)
		{
			value1 = card_conversion(tmp);
			value2 = card_conversion(tmp->next);
			if (value2 < value1)
			{
				node_swap(deck, tmp);
				_swap = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!_swap)
			break;
		_swap = 0;
		for (; idx > low; idx--)
		{
			value1 = card_conversion(tmp);
			value2 = card_conversion(tmp->prev);
			if (value2 > value1)
			{
				node_swap(deck, tmp->prev);
				_swap = 1;
			}
			else
				tmp = tmp->prev;
		}
		high -= 1;
		low += 1;
	}
}
