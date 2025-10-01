#include <stdio.h>
#include <stdlib.h>

// Function to sort using Bucket Sort
void bucketSort(float arr[], int n) {
    int i, j, k;
    
    // Create n empty buckets (arrays)
    float **buckets = (float **)malloc(n * sizeof(float *));
    int *bucket_sizes = (int *)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++) bucket_sizes[i] = 0;

    // Put array elements into buckets
    for (i = 0; i < n; i++) {
        int index = n * arr[i]; // map element to bucket
        bucket_sizes[index]++;
        buckets[index] = (float *)realloc(buckets[index], bucket_sizes[index] * sizeof(float));
        buckets[index][bucket_sizes[index]-1] = arr[i];
    }

    // Sort individual buckets (Insertion Sort)
    for (i = 0, k = 0; i < n; i++) {
        for (j = 1; j < bucket_sizes[i]; j++) {
            float key = buckets[i][j];
            int l = j - 1;
            while (l >= 0 && buckets[i][l] > key) {
                buckets[i][l + 1] = buckets[i][l];
                l--;
            }
            buckets[i][l + 1] = key;
        }

        // Concatenate buckets
        for (j = 0; j < bucket_sizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Free memory
    for (i = 0; i < n; i++) free(buckets[i]);
    free(buckets);
    free(bucket_sizes);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0;i<n;i++) printf("%.2f ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for(int i=0;i<n;i++) printf("%.2f ", arr[i]);

    return 0;
}
