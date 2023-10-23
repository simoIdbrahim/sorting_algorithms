#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - function one
 * @s1: arg one string to be compared.
 * @s2: arg two string to be compared.
 * Return: int
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	return (0);
}

/**
 * get_value -function two.
 * @card: arg one pointer deck_node_t card.
 * Return: str.
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
	{
		return (0);
	}
	if (_strcmp(card->card->value, "1") == 0)
	{
		return (1);
	}
	if (_strcmp(card->card->value, "2") == 0)
	{
		return (2);
	}
	if (_strcmp(card->card->value, "3") == 0)
	{
		return (3);
	}
	if (_strcmp(card->card->value, "4") == 0)
	{
		return (4);
	}
	if (_strcmp(card->card->value, "5") == 0)
	{
		return (5);
	}
	if (_strcmp(card->card->value, "6") == 0)
	{
		return (6);
	}
	if (_strcmp(card->card->value, "7") == 0)
	{
		return (7);
	}
	if (_strcmp(card->card->value, "8") == 0)
	{
		return (8);
	}
	if (_strcmp(card->card->value, "9") == 0)
	{
		return (9);
	}
	if (_strcmp(card->card->value, "10") == 0)
	{
		return (10);
	}
	if (_strcmp(card->card->value, "Jack") == 0)
	{
		return (11);
	}
	if (_strcmp(card->card->value, "Queen") == 0)
	{
		return (12);
	}
	return (13);
}

/**
 * insertion_sort_deck_kind - function three.
 * @deck: arg one pointer head deck_node_t doubly-linked list.
 * Return: void
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *it, *ins, *t;

	for (it = (*deck)->next; it != NULL; it = t)
	{
		t = it->next;
		ins = it->prev;
		while (ins != NULL && ins->card->kind > it->card->kind)
		{
			ins->next = it->next;
			if (it->next != NULL)
			{
				it->next->prev = ins;
			}
			it->prev = ins->prev;
			it->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = it;
			else
				*deck = it;
			ins->prev = it;
			ins = it->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - four.
 * @deck: arg one pointer head deck_node_t doubly-linked list.
 * Return: void
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *it, *ins, *t;

	for (it = (*deck)->next; it != NULL; it = t)
	{
		t = it->next;
		ins = it->prev;
		while (ins != NULL &&
		       ins->card->kind == it->card->kind &&
		       get_value(ins) > get_value(it))
		{
			ins->next = it->next;
			if (it->next != NULL)
			{
				it->next->prev = ins;
			}
			it->prev = ins->prev;
			it->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = it;
			else
				*deck = it;
			ins->prev = it;
			ins = it->prev;
		}
	}
}

/**
 * sort_deck - function five.
 * @deck: arg one pointer head deck_node_t doubly-linked list.
 * Return: void
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{
		return;
	}

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}

