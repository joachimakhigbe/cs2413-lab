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