#include <stdio.h>

void quickSortHelper(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void quickSort(int arr[], int size) {
    if (size <= 1) {
        return;  // Base case: empty array or single element
    }
    quickSortHelper(arr, 0, size - 1);
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);
        
        // Recursively sort the left and right parts
        quickSortHelper(arr, low, pivotIndex - 1);
        quickSortHelper(arr, pivotIndex + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];
    
    // Index of the smaller element (indicates the right position of pivot)
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap arr[i+1] and arr[high] (put pivot in correct position)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    // Return the partition index
    return i + 1;
}

// Alternative partition function using first element as pivot
int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    
    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j > low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap pivot with arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    
    return j;
}

// Helper function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    quickSort(arr, size);
    
    printf("Sorted array:   ");
    printArray(arr, size);
    
    // Test with duplicate values
    int arr2[] = {5, 2, 8, 2, 9, 1, 5, 5, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\nOriginal array (with duplicates): ");
    printArray(arr2, size2);
    
    quickSort(arr2, size2);
    
    printf("Sorted array (with duplicates):   ");
    printArray(arr2, size2);
    
    // Test with already sorted array
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("\nOriginal array (already sorted): ");
    printArray(arr3, size3);
    
    quickSort(arr3, size3);
    
    printf("Sorted array (already sorted):   ");
    printArray(arr3, size3);
    
    // Test with reverse sorted array
    int arr4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("\nOriginal array (reverse sorted): ");
    printArray(arr4, size4);
    
    quickSort(arr4, size4);
    
    printf("Sorted array (reverse sorted):   ");
    printArray(arr4, size4);
    
    return 0;
}