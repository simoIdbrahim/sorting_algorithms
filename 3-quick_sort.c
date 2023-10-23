#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - fucntion one.
 * @a: arg one int.
 * @b: arg two int.
 */

void swap_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * lomuto_partition - function two.
 * @array: arge one array int.
 * @size: arge two array size.
 * @left: arg three the start array ind.
 * @right: arg four the end of array ind.
 * Return: final index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *p, a, b;

	p = array + right;
	for (a = b = left; b < right; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *p)
	{
		swap_ints(array + a, p);
		print_array(array, size);
	}

	return (a);
}

/**
 * lomuto_sort - function three.
 * @array: arg one array int to sort.
 * @size: arg two array size.
 * @left: arg three the start array ind.
 * @right: arg four the end array ind.
 * Return: void.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - functio four.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}
