#include "sort.h"

/**
 * swap_ints - function one.
 * @a: arg one int.
 * @b: arg two int.
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
 * shell_sort - function two.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t g, ind1, ind2;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (g = 1; g < (size / 3);)
	{
		g = g * 3 + 1;
	}

	for (; g >= 1; g /= 3)
	{
		for (ind1 = g; ind1 < size; ind1++)
		{
			ind2 = ind1;
			while (ind2 >= g && array[ind2 - g] > array[ind2])
			{
				swap_ints(array + ind2, array + (ind2 - g));
				ind2 -= g;
			}
		}
		print_array(array, size);
	}
}
