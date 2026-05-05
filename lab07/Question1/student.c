#include <stdbool.h>

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