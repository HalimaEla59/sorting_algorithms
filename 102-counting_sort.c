#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size) {
    // Find the maximum element to determine the range
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Create a counting array of size (max + 1)
    int* counting_array = (int*)malloc((max + 1) * sizeof(int));
    if (counting_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize counting array to 0
    for (int i = 0; i <= max; i++) {
        counting_array[i] = 0;
    }

    // Count occurrences of each element
    for (size_t i = 0; i < size; i++) {
        counting_array[array[i]]++;
    }

    // Print the counting array
    printf("Counting array: ");
    for (int i = 0; i <= max; i++) {
        printf("%d ", counting_array[i]);
    }
    printf("\n");

    // Reconstruct the sorted array
    size_t index = 0;
    for (int i = 0; i <= max; i++) {
        while (counting_array[i] > 0) {
            array[index++] = i;
            counting_array[i]--;
        }
    }

    // Free dynamically allocated memory
    free(counting_array);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 9, 6, 5, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
