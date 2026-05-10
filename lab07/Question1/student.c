#include <stdbool.h>
#include <stdio.h>

// Standard bubble sort
void bubbleSort(int arr[], int size) {
    // If array is empty or has one element, do nothing
    if (size <= 1) {
        return;
    }
    
    // Outer loop for each pass
    for (int i = 0; i < size - 1; i++) {
        // Inner loop for comparing adjacent elements
        // After each pass, the largest element bubbles to the end
        // so we can reduce the range of inner loop
        for (int j = 0; j < size - 1 - i; j++) {
            // If current element is greater than next element, swap them
            if (arr[j] > arr[j + 1]) {
                // Swap using temporary variable
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Optimized bubble sort with early termination
void bubbleSortOptimized(int arr[], int size) {
    // If array is empty or has one element, do nothing
    if (size <= 1) {
        return;
    }
    
    // Outer loop for each pass
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;  // Flag to track if any swap occurred
        
        // Inner loop for comparing adjacent elements
        // After each pass, the largest element bubbles to the end
        for (int j = 0; j < size - 1 - i; j++) {
            // If current element is greater than next element, swap them
            if (arr[j] > arr[j + 1]) {
                // Swap using temporary variable
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;  // A swap occurred
            }
        }
        
        // If no swaps occurred in this pass, array is sorted
        // We can break early
        if (!swapped) {
            break;
        }
    }
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
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, size1);
    
    bubbleSort(arr1, size1);
    printf("Sorted array (standard): ");
    printArray(arr1, size1);
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\nOriginal array: ");
    printArray(arr2, size2);
    
    bubbleSortOptimized(arr2, size2);
    printf("Sorted array (optimized): ");
    printArray(arr2, size2);
    
    return 0;
}