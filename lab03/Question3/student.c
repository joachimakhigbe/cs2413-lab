#include "student.h"

bool hasCycle(struct ListNode *head) {
    // Handle empty list or single node
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    // Initialize slow and fast pointers
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Move slow pointer one step and fast pointer two steps at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move one step
        fast = fast->next->next;   // Move two steps
        
        // If slow and fast meet, there's a cycle
        if (slow == fast) {
            return true;
        }
    }
    
    // If we reach here, fast reached the end (no cycle)
    return false;
}