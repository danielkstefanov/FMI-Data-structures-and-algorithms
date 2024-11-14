#include "TreeNode.h"

class Solution {
public:
    void preorderTraversalRecursive(TreeNode* root, int currentDepth,
        int& maxDepth) {
        if (root != nullptr) {
            if (currentDepth > maxDepth)
                maxDepth = currentDepth;

            preorderTraversalRecursive(root->left, currentDepth + 1, maxDepth);
            preorderTraversalRecursive(root->right, currentDepth + 1, maxDepth);
        }
    }

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int maxDepth = 1;
        preorderTraversalRecursive(root, 1, maxDepth);
        return maxDepth;
    }
};