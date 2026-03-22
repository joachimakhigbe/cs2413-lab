#include <stdbool.h>  // For bool, true, false
#include <stddef.h>   // For NULL

// Definition of TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check if two trees are mirror images
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // If both are NULL, they're mirrors
    if (left == NULL && right == NULL) {
        return true;
    }
    
    // If one is NULL and the other isn't, they're not mirrors
    if (left == NULL || right == NULL) {
        return false;
    }
    
    // Check if current nodes have same value AND
    // left's left is mirror of right's right AND
    // left's right is mirror of right's left
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    // An empty tree is symmetric
    if (root == NULL) {
        return true;
    }
    
    // Check if left and right subtrees are mirrors of each other
    return isMirror(root->left, root->right);
}