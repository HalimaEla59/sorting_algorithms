#include "sort.h"

/**
 * lomuto_partition - lomuto partition scheme
 * @end: ending number
 * @start: starting number
 * @array: our array to sort
 * @size: size of array
 * Return: int
 */
int lomuto_partition(int *array, int start, int end, int size)
{
	int pi = array[end];
	int i = start, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pi)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recur - quick sorting recursively
 * @end: ending number
 * @start: starting number
 * @array: our array to sort
 * @size: size of the array
 */
void quick_sort_recur(int *array, int start, int end, int size)
{
	int pi;

	if (start < end)
	{
		pi = lomuto_partition(array, start, end, size);
		quick_sort_recur(array, start, pi - 1, size);
		printf("%d start %d pivot %d size\n", start, pi - 1, size);
		quick_sort_recur(array, pi + 1, end, size);
		printf("%d start %d pivot %d size\n", start, pi + 1, size);
	}
}

/**
 * quick_sort - quick sorts an array of int
 * @array: the array to sort ascendingly
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recur(array, 0, size - 1, size);
}
