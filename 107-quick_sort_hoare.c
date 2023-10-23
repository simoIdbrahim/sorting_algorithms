#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - function one.
 * @a: arg one int to swap.
 * @b: arg two int to swap.
 */

void swap_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * hoare_partition - function two.
 * @array: arg one array int.
 * @size: arg two array size.
 * @left: arg three start index subset to order.
 * @right: arg foure end index subset to order.
 * Return: last partition ind.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int p, a, b;

	p = array[right];
	for (a = left - 1, b = right + 1; a < b;)
	{
		do {
			a++;
		} while (array[a] < p);
		do {
			b--;
		} while (array[b] > p);

		if (a < b)
		{
			swap_ints(array + a, array + b);
			print_array(array, size);
		}
	}

	return (a);
}

/**
 * hoare_sort - function three.
 * @array: arg one array int.
 * @size: arg two array size.
 * @left: arg three start index array partition to order.
 * @right: arg four end index array partition to ordere.
 * Return: void
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - function four.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	hoare_sort(array, size, 0, size - 1);
}
