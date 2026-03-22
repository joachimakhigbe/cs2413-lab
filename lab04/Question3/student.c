#include <stddef.h>  // For NULL

// Definition of TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function for DFS traversal
void dfs(struct TreeNode* node, int currentSum, int* total) {
    if (node == NULL) {
        return;
    }
    
    // Update current number by appending current node's digit
    // currentSum * 10 shifts existing digits left and adds new digit
    currentSum = currentSum * 10 + node->val;
    
    // If it's a leaf node, add to total
    if (node->left == NULL && node->right == NULL) {
        *total += currentSum;
        return;
    }
    
    // Recursively traverse left and right subtrees
    dfs(node->left, currentSum, total);
    dfs(node->right, currentSum, total);
}

int sumNumbers(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int total = 0;
    dfs(root, 0, &total);
    return total;
}