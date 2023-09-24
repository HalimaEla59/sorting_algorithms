#include "sort.h"

/**
 * bubble_sort - bubble sorts an array of int (assending)
 * @array: the array of ints
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp, counter = 0;
	size_t i, j, size2 = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		counter = 0;
		for (j = 0; j < size2 - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				counter++;
				print_array(array, size);
			}
		}
		if (counter == 0)
			break;
		size2--;
	}
}
