#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints list int
 * @list: arg one list printed
 * Return: void
 */

void print_list(const listint_t *list)
{
	int ind = 0;

	while (list)
	{
		if (ind > 0)
		{
			printf(", ");
		}
		printf("%d", list->n);
		++ind;
		list = list->next;
	}
	printf("\n");
}
