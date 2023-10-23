#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - function one.
 * @subarr: arg one.
 * @buff: arg two.
 * @front: arg three
 * @mid: arg four.
 * @back: arg five.
 * Return: void
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t ind1, ind2, ind3 = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (ind1 = front, ind2 = mid; ind1 < mid && ind2 < back; ind3++)
	{
		buff[ind3] = (subarr[ind1] < subarr[ind2]) ? subarr[ind1++] : subarr[ind2++];
	}
	for (; ind1 < mid; ind1++)
	{
		buff[ind3++] = subarr[ind1];
	}
	for (; ind2 < back; ind2++)
	{
		buff[ind3++] = subarr[ind2];
	}
	for (ind1 = front, ind3 = 0; ind1 < back; ind1++)
	{
		subarr[ind1] = buff[ind3++];
	}

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - function two.
 * @subarr: arg one.
 * @buff: arg two.
 * @front: arg three.
 * @back: arg four.
 * Return: void
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t m;

	if (back - front > 1)
	{
		m = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, m);
		merge_sort_recursive(subarr, buff, m, back);
		merge_subarr(subarr, buff, front, m, back);
	}
}

/**
 * merge_sort - fucntion three.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void.
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
	{
		return;
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		return;
	}

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
