#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - func one.
 * @a: arg one int to swap.
 * @b: arg two int to swap.
 * Retur: void
 */

void swap_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * bitonic_merge - function two.
 * @array: arg one array int.
 * @size: arg two array size.
 * @start: arg three start ind of the sequence in array.
 * @seq: arg four size of the sequence.
 * @flow: arg five direction to sort in.
 * Return: void
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t ind, j = seq / 2;

	if (seq > 1)
	{
		for (ind = start; ind < start + j; ind++)
		{
			if ((flow == UP && array[ind] > array[ind + j]) ||
			    (flow == DOWN && array[ind] < array[ind + j]))
				swap_ints(array + ind, array + ind + j);
		}
		bitonic_merge(array, size, start, j, flow);
		bitonic_merge(array, size, start + j, j, flow);
	}
}

/**
 * bitonic_seq - functuin three.
 * @array: arg one array int.
 * @size: arg two array size.
 * @start: arg three start ind of the sequence in array.
 * @seq: arg four size of the sequence.
 * @flow: arg five direction to sort in.
 * Return: void
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t c = seq / 2;
	char *string = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, c, UP);
		bitonic_seq(array, size, start + c, c, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - function four.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_seq(array, size, 0, size, UP);
}
