#include <stdio.h>

long long merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    long long invCount = 0;
    
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            invCount += leftSize - i; // Increment invCount by the number of remaining elements in the left subarray
        }
        k++;
    }
    
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
    return invCount;
}

long long mergeSort(int arr[], int size) {
    if (size < 2) {
        return 0;
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    long long invCount = 0;
    
    invCount += mergeSort(left, mid); // Count inversions in left subarray
    invCount += mergeSort(right, size - mid); // Count inversions in right subarray
    invCount += merge(arr, left, mid, right, size - mid); // Merge two sorted subarrays and count inversions
    
    return invCount;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 5, 1, 3, 8, 4, 2, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    long long inversions = mergeSort(arr, size);
    
    printf("Sorted array: ");
    printArray(arr, size);
    
    printf("Number of inversions: %lld\n", inversions);
    
    return 0;
}
