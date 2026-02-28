#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only one node, no swapping needed
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Initialize pointers
    struct ListNode* newHead = head->next;  // The second node becomes the new head
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL && curr->next != NULL) {
        struct ListNode* next = curr->next;      // The node to swap with curr
        struct ListNode* nextPair = next->next;  // The start of the next pair
        
        // Swap the current pair
        next->next = curr;    // Point the second node to the first
        curr->next = nextPair; // Point the first node to the next pair
        
        // Connect the previous pair to this swapped pair
        if (prev != NULL) {
            prev->next = next;
        }
        
        // Move pointers forward
        prev = curr;
        curr = nextPair;
    }
    
    return newHead;
}