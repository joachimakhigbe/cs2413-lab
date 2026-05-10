#include <stdio.h>

void selectionSort(int arr[], int size) {
    // If array is empty or has only one element, do nothing
    if (size <= 1) {
        return;
    }
    
    // Iterate through each position in the array
    for (int i = 0; i < size - 1; i++) {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of unsorted portion
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Alternative implementation for descending order
void selectionSortDescending(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
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

// Function to demonstrate each step of selection sort (for learning)
void selectionSortWithSteps(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    printf("Starting selection sort:\n");
    printArray(arr, size);
    printf("\n");
    
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in unsorted portion
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap if needed
        if (minIndex != i) {
            printf("Pass %d: Swap arr[%d]=%d with arr[%d]=%d\n", 
                   i + 1, i, arr[i], minIndex, arr[minIndex]);
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        } else {
            printf("Pass %d: No swap needed (arr[%d]=%d is already in correct position)\n", 
                   i + 1, i, arr[i]);
        }
        
        printf("Array after pass %d: ", i + 1);
        printArray(arr, size);
        printf("\n");
    }
}

int main() {
    // Test with the example array
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    selectionSort(arr, size);
    
    printf("Sorted array:   ");
    printArray(arr, size);
    
    // Test with step-by-step visualization
    printf("\n--- Step-by-Step Demonstration ---\n");
    int arr2[] = {64, 25, 12, 22, 11};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    selectionSortWithSteps(arr2, size2);
    
    // Test different scenarios
    printf("\n--- Additional Test Cases ---\n");
    
    // Test 1: Already sorted array
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Already sorted: ");
    printArray(arr1, size1);
    selectionSort(arr1, size1);
    printf("After sort:      ");
    printArray(arr1, size1);
    
    // Test 2: Reverse sorted array
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\nReverse sorted:  ");
    printArray(arr3, size3);
    selectionSort(arr3, size3);
    printf("After sort:      ");
    printArray(arr3, size3);
    
    // Test 3: Array with duplicates
    int arr4[] = {5, 2, 8, 2, 9, 1, 5, 5, 3, 7};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("\nWith duplicates: ");
    printArray(arr4, size4);
    selectionSort(arr4, size4);
    printf("After sort:      ");
    printArray(arr4, size4);
    
    // Test 4: Single element
    int arr5[] = {42};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("\nSingle element:  ");
    printArray(arr5, size5);
    selectionSort(arr5, size5);
    printf("After sort:      ");
    printArray(arr5, size5);
    
    // Test 5: Two elements
    int arr6[] = {5, 3};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("\nTwo elements:    ");
    printArray(arr6, size6);
    selectionSort(arr6, size6);
    printf("After sort:      ");
    printArray(arr6, size6);
    
    // Test 6: Descending order
    int arr7[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 33};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("\n--- Descending Order ---\n");
    printf("Original array:  ");
    printArray(arr7, size7);
    selectionSortDescending(arr7, size7);
    printf("Sorted descending: ");
    printArray(arr7, size7);
    
    return 0;
}