#include "sort.h"

/**
 * counting_sort - counting sorting an array
 * @array: array to sort ascendingly
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int j, max = array[0], *counting_array;
	size_t i, index = 0;

	for (i = 1; i < size; i++) /*finding the max element*/
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	counting_array = (int *)malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	for (j = 0; j <= max; j++) /*initialise the counting array*/
		counting_array[j] = 0;
	for (i = 0; i < size; i++) /*counting occurances*/
		counting_array[array[i]]++;
	for (j = 0; j <= max; j++) /*printing*/
		printf("%d ", counting_array[i]);
	for (j = 0; j <= max; j++) /*reconstruct the sorted array*/
	{
		while (counting_array[j] > 0)
		{
			array[index++] = j;
			counting_array[j]--;
		}
	}
	free(counting_array);
}
