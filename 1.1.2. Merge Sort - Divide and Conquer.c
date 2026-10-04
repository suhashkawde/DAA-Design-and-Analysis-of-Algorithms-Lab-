/**
 * @file 1.1.2. Merge Sort - Divide and Conquer.c
 * @brief Sort an array of n integers in non-decreasing order using the Merge Sort algorithm.
 * @strategy Divide and Conquer
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(n log n)
 *     - Average Case: O(n log n)
 *     - Worst Case: O(n log n)
 *   - Space Complexity: O(n) [Auxiliary space for merging subarrays]
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Merges two sorted subarrays into a single sorted array.
 * @param arr The array containing the subarrays.
 * @param left Starting index of the first subarray.
 * @param mid Ending index of the first subarray.
 * @param right Ending index of the second subarray.
 */
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Allocate memory for temporary arrays L and R
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in merge().\n");
        exit(1);
    }

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Free allocated memory
    free(L);
    free(R);
}

/**
 * @brief Recursively divides the array into subarrays until each subarray has a single element.
 * @param arr The array to be sorted.
 * @param left Starting index of the subarray.
 * @param right Ending index of the subarray.
 */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calculate mid to avoid potential overflow for large indices
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input element.\n");
            free(arr);
            return 1;
        }
    }

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array elements
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Clean up allocated memory
    free(arr);
    return 0;
}
