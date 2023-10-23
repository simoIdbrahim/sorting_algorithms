#include "sort.h"

/**
 * swap_ints - function one.
 * @a: arg one.
 * @b: arg two.
 * Return: void
 */

void swap_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - function two
 * @array: arg array int number
 * @size: arg array size
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int *num;
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		num = array + i;
		for (j = i + 1; j < size; j++)
		{
			num = (array[j] < *num) ? (array + j) : num;
		}

		if ((array + i) != num)
		{
			swap_ints(array + i, num);
			print_array(array, size);
		}
	}
}
