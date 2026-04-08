#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key) {
    // Handle negative keys properly
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}

static int find(Node* table[], int key, int* value) {
    int idx = hash(key);
    Node* current = table[idx];
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize hash table
    Node* table[TABLE_SIZE] = {NULL};
    int* result = NULL;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;
        
        // Check if complement exists in hash table
        if (find(table, complement, &foundIndex)) {
            // Found the pair
            result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }
        
        // Insert current element into hash table
        insert(table, nums[i], i);
    }
    
    // According to the problem, a solution always exists
    // This line should never be reached
    *returnSize = 0;
    freeTable(table);
    return NULL;
}