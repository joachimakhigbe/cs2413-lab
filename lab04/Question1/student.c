#include <stddef.h>  // For NULL

// Definition of TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    // Base case: empty tree
    if (root == NULL) {
        return 0;
    }
    
    // Recursively find depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // Return 1 (for current node) plus the maximum depth of subtrees
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}