#include <vector>

#include "TreeNode.h"

using namespace std;

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

    void rrlTraversal(TreeNode* current, vector<int>& answer, int currentDepth) {
        if (current != nullptr) {
            rrlTraversal(current->right, answer, currentDepth + 1);

            if (answer[currentDepth] == INT_MIN)
                answer[currentDepth] = current->val;

            rrlTraversal(current->left, answer, currentDepth + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer(maxDepth(root), INT_MIN);
        rrlTraversal(root, answer, 0);
        return answer;
    }
};