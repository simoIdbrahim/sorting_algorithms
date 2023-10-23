#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - function one.
 * @list: arg one.
 * @tail: arg two.
 * @shaker: arg three.
 * Return: void
 */

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
	{
		(*shaker)->prev->next = tmp;
	}
	else
	{
		*list = tmp;
	}
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = *shaker;
	}
	else
	{
		*tail = *shaker;
	}
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - function two.
 * @list: arg one.
 * @tail: arg two.
 * @shaker: arg three.
 * Return: void
 */

void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
	{
		(*shaker)->next->prev = tmp;
	}
	else
	{
		*tail = tmp;
	}

	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;

	if (tmp->prev != NULL)
	{
		tmp->prev->next = *shaker;
	}
	else
	{
		*list = *shaker;
	}

	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - function three.
 * @list: arg one.
 * Returm: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool true_false = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (tail = *list; tail->next != NULL;)
	{
		tail = tail->next;
	}

	while (true_false == false)
	{
		true_false = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				true_false = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				true_false = false;
			}
		}
	}
}
