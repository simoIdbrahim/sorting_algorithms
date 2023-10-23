#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - the printer array int
 * @array: arg one array printing
 * @size: arg two elements in array
 * Return: void
 */

void print_array(const int *array, size_t size)
{
	size_t ind;

	ind = 0;
	while (array && ind < size)
	{
		if (ind > 0)
		{
			printf(", ");
		}
		printf("%d", array[ind]);
		++ind;
	}
	printf("\n");
}
