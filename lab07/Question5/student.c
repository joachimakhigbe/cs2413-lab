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