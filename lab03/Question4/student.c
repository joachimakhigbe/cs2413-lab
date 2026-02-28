#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // Handle empty list case
    if (head == NULL) {
        return -1; // or some error value
    }
    
    // Initialize slow and fast pointers
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Move fast pointer twice as fast as slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // slow moves one step
        fast = fast->next->next;  // fast moves two steps
    }
    
    // When fast reaches the end, slow is at the middle
    // For even length, this gives the second middle node
    return slow->val;
}