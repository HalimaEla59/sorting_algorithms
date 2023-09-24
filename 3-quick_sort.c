#include "sort.h"


void swap(int* a, int* b, int *array, size_t size) {
    int t = *a;
    *a = *b;
    *b = t;
    
    // Print array after swap
    print_array(array, size);
}

int lomuto_partition(int arr[], int low, int high, int *array, size_t size) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j], array, size);
        }
    }
    swap(&arr[i + 1], &arr[high], array, size);
    return i + 1;
}

void quick_sort_recursive(int arr[], int low, int high, int *array, size_t size) {
    if (low < high) {
        int pi = lomuto_partition(arr, low, high, array, size);

        quick_sort_recursive(arr, low, pi - 1, array, size);
        quick_sort_recursive(arr, pi + 1, high, array, size);
    }
}

/**
 * quick_sort - quick sorts an array of int
 * @array: the array to sort ascendingly
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size) {
    quick_sort_recursive(array, 0, size - 1, array, size);
}
