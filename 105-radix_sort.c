#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - fucntion one
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: The max int in array.
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
 * radix_counting_sort - function two.
 * @array: arg one array int.
 * @size: arg two array size.
 * @sig: arg three digit to sort.
 * @buff: arg four buffer to store array.
 * Return: void
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t ind;

	for (ind = 0; ind < size; ind++)
	{
		counter[(array[ind] / sig) % 10] += 1;
	}

	for (ind = 0; ind < 10; ind++)
	{
		counter[ind] += counter[ind - 1];
	}

	for (ind = size - 1; (int)ind >= 0; ind--)
	{
		buff[counter[(array[ind] / sig) % 10] - 1] = array[ind];
		counter[(array[ind] / sig) % 10] -= 1;
	}

	for (ind = 0; ind < size; ind++)
	{
		array[ind] = buff[ind];
	}
}

/**
 * radix_sort - function three.
 * @array: arg one array int.
 * @size: arg two array size.
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int m, s, *buffer;

	if (array == NULL || size < 2)
	{
		return;
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		return;
	}

	m = get_max(array, size);
	for (s = 1; m / s > 0; s *= 10)
	{
		radix_counting_sort(array, size, s, buffer);
		print_array(array, size);
	}

	free(buffer);
}
