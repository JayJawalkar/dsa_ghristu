#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int i;

    // Find the maximum element
    int max = arr[0];
    for(i=1;i<n;i++)
        if(arr[i] > max) max = arr[i];

    // Create count array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store count of each element
    for(i=0;i<n;i++)
        count[arr[i]]++;

    // Build the sorted array
    int index = 0;
    for(i=0;i<=max;i++)
        while(count[i]-- > 0)
            arr[index++] = i;

    free(count);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);

    countingSort(arr, n);

    printf("\nSorted array: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);

    return 0;
}
