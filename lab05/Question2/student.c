#include <stdlib.h>

static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
 * Returns the kth largest element in the array using a min-heap of size k.
 */
int findKthLargest(int* nums, int numsSize, int k) {
    // Create a min-heap to store the k largest elements seen so far
    int heap[k];          // VLA (Variable Length Array) – valid in C99
    int heapSize = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (heapSize < k) {
            // Insert the element into the heap
            heap[heapSize] = nums[i];
            heapifyUp(heap, heapSize);
            ++heapSize;
        } else {
            // If current element is larger than the smallest among the top k
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                heapifyDown(heap, k, 0);
            }
        }
    }

    // The root of the min-heap is the kth largest element
    return heap[0];
}

/* Swap two integers */
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Restore min-heap property upward from the given index */
static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

/* Restore min-heap property downward from the given index */
static void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}