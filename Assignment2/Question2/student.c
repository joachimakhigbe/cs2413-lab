#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

static int checkAVL(struct TreeNode* root, long long low, long long high) {
    if (root == NULL) {
        return 0;
    }

    if ((long long)root->val <= low || (long long)root->val >= high) {
        return -1;
    }

    int leftHeight = checkAVL(root->left, low, (long long)root->val);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkAVL(root->right, (long long)root->val, high);
    if (rightHeight == -1) {
        return -1;
    }

    int diff = leftHeight - rightHeight;
    if (diff < -1 || diff > 1) {
        return -1;
    }

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1) != -1;
}