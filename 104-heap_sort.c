#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - function one
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
 * max_heapify - function two.
 * @array: arg one array int.
 * @size: arg two array size.
 * @base: arg three array ind.
 * @root: arg four root node.
 * Return: void
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, big;

	l = 2 * root + 1;
	r = 2 * root + 2;
	big = root;

	if (l < base && array[l] > array[big])
	{
		big = l;
	}
	if (r < base && array[r] > array[big])
	{
		big = r;
	}

	if (big != root)
	{
		swap_ints(array + root, array + big);
		print_array(array, size);
		max_heapify(array, size, base, big);
	}
}

/**
 * heap_sort - function three.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int ind;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (ind = (size / 2) - 1; ind >= 0; ind--)
	{
		max_heapify(array, size, size, ind);
	}

	for (ind = size - 1; ind > 0; ind--)
	{
		swap_ints(array, array + ind);
		print_array(array, size);
		max_heapify(array, size, ind, 0);
	}
}
