#include "sort.h"

/**
 * swap - swaps two numbres and prints the array after
 * @a: firt int to swap
 * @b: second int to swap
 * @array: the array of ints
 * @size: size of array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int t = *a;

	*a = *b;
	*b = t;

	print_array(array, size);
}

/**
 * lomuto_partition - lomuto partition scheme
 * @arr: array to part
 * @low: lowest number
 * @high: highest number
 * @array: our array to sort
 * @size: size of array
 * Return: int
 */
int lomuto_partition(int arr[], int low, int high, int *array, size_t size)
{
	int pivot = arr[high];
	int j, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j], array, size);
		}
	}
	swap(&arr[i + 1], &arr[high], array, size);
	return (i + 1);
}

/**
 * quick_sort_recur - quick sorting recursively
 * @arr: arr of ints
 * @low: lowest number
 * @high: highest number
 * @array: our array to sort
 * @size: size of the array
 */
void quick_sort_recur(int arr[], int low, int high, int *array, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(arr, low, high, array, size);
		quick_sort_recur(arr, low, pi - 1, array, size);
		quick_sort_recur(arr, pi + 1, high, array, size);
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
	quick_sort_recur(array, 0, size - 1, array, size);
}
