#include <unordered_map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };
 

class Solution {
private:

    unordered_map<TreeNode*, int> dp;

    int helper(TreeNode* current)
    {
        if (!current)
            return 0;

        if (dp.count(current))
            return dp[current];

        int currentBest = current->val;

        if (current->left) {
            currentBest += helper(current->left->left);
            currentBest += helper(current->left->right);
        }

        if (current->right) {
            currentBest += helper(current->right->left);
            currentBest += helper(current->right->right);
        }

        currentBest = max(currentBest, helper(current->left) + helper(current->right));

        dp[current] = currentBest;

        return currentBest;
    }

public:
    int rob(TreeNode* root) { return helper(root); }
};