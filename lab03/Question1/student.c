#include "student.h"
#include <stddef.h>  // For NULL definition

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    
    while (current != NULL) {
        // Store the next node
        next = current->next;
        
        // Reverse the link - point current node to previous node
        current->next = prev;
        
        // Move prev and current pointers one step forward
        prev = current;
        current = next;
    }
    
    // prev becomes the new head of the reversed list
    return prev;
}