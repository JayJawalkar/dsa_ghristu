#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Counting sort used by radix sort for a particular digit
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};

    // Store count of occurrences of each digit
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output to arr[]
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix sort main function
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    // Apply counting sort for each digit
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    radixSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
