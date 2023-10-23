#include "sort.h"

/**
 * swap_ints - function one.
 * @a: arg one.
 * @b: arg two.
 * Return: void
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - function two.
 * @array: arg one.
 * @size: arg two.
 * Return: void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t ind, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (ind = 0; ind < length - 1; ind++)
		{
			if (array[ind] > array[ind + 1])
			{
				swap_ints(array + ind, array + ind + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
