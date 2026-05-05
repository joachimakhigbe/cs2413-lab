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