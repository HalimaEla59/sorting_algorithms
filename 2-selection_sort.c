#include "sort.h"

/**
 * selection_sort - selection sorting an array of ints
 * @array: the array to sort ascendingly
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int min, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				k = j;
			}
		}
		if (array[i] != min)
		{
			temp = array[i];
			array[i] = min;
			array[k] = temp;
			print_array(array, size);
		}
	}
}
