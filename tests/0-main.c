#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t num = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, num);
	printf("\n");
	bubble_sort(arr, num);
	printf("\n");
	print_array(arr, num);
	return (0);
}
