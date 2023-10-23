#include "sort.h"

/**
 * get_max - function one.
 * @array: arg one array in.
 * @size: arg two array size.
 * Return: max int in array.
 */

int get_max(int *array, int size)
{
	int m, ind;

	for (m = array[0], ind = 1; ind < size; ind++)
	{
		if (array[ind] > m)
		{
			m = array[ind];
		}
	}

	return (m);
}

/**
 * counting_sort - function two.
 * @array: arg one array in.
 * @size: arg two array size.
 * Return: void.
 */

void counting_sort(int *array, size_t size)
{
	int *cou, *sor, m, ind;

	if (array == NULL || size < 2)
	{
		return;
	}

	sor = malloc(sizeof(int) * size);
	if (sor == NULL)
	{
		return;
	}
	m = get_max(array, size);
	cou = malloc(sizeof(int) * (m + 1));
	if (cou == NULL)
	{
		free(sor);
		return;
	}

	for (ind = 0; ind < (m + 1); ind++)
	{
		cou[ind] = 0;
	}
	for (ind = 0; ind < (int)size; ind++)
	{
		cou[array[ind]] += 1;
	}
	for (ind = 0; ind < (m + 1); ind++)
	{
		cou[ind] += cou[ind - 1];
	}
	print_array(cou, m + 1);

	for (ind = 0; ind < (int)size; ind++)
	{
		sor[cou[array[ind]] - 1] = array[ind];
		cou[array[ind]] -= 1;
	}

	for (ind = 0; ind < (int)size; ind++)
	{
		array[ind] = sor[ind];
	}

	free(sor);
	free(cou);
}
