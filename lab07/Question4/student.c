#include <stdio.h>

void insertionSort(int arr[], int size) {
    // If array has 0 or 1 element, it's already sorted
    if (size <= 1) {
        return;
    }
    
    // Start from the second element (index 1) to the end
    for (int i = 1; i < size; i++) {
        int key = arr[i];  // Current element to be inserted
        int j = i - 1;     // Index of the last element in the sorted portion
        
        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Place key in its correct position
        arr[j + 1] = key;
    }
}

// Alternative implementation with descriptive variable names
void insertionSortDescriptive(int arr[], int size) {
    for (int currentIndex = 1; currentIndex < size; currentIndex++) {
        int valueToInsert = arr[currentIndex];
        int sortedIndex = currentIndex - 1;
        
        // Move elements that are greater than valueToInsert one position ahead
        while (sortedIndex >= 0 && arr[sortedIndex] > valueToInsert) {
            arr[sortedIndex + 1] = arr[sortedIndex];
            sortedIndex--;
        }
        
        // Insert the value at the correct position
        arr[sortedIndex + 1] = valueToInsert;
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    insertionSort(arr, size);
    
    printf("Sorted array:   ");
    printArray(arr, size);
    
    // Test with different scenarios
    printf("\n--- Additional Test Cases ---\n");
    
    // Test 1: Already sorted array
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Already sorted: ");
    printArray(arr1, size1);
    insertionSort(arr1, size1);
    printf("After sort:      ");
    printArray(arr1, size1);
    
    // Test 2: Reverse sorted array
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\nReverse sorted:  ");
    printArray(arr2, size2);
    insertionSort(arr2, size2);
    printf("After sort:      ");
    printArray(arr2, size2);
    
    // Test 3: Array with duplicates
    int arr3[] = {5, 2, 8, 2, 9, 1, 5, 5, 3, 7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\nWith duplicates: ");
    printArray(arr3, size3);
    insertionSort(arr3, size3);
    printf("After sort:      ");
    printArray(arr3, size3);
    
    // Test 4: Single element
    int arr4[] = {42};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("\nSingle element:  ");
    printArray(arr4, size4);
    insertionSort(arr4, size4);
    printf("After sort:      ");
    printArray(arr4, size4);
    
    // Test 5: Two elements
    int arr5[] = {5, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("\nTwo elements:    ");
    printArray(arr5, size5);
    insertionSort(arr5, size5);
    printf("After sort:      ");
    printArray(arr5, size5);
    
    return 0;
}