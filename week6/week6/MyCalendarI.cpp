#include "iostream"

using namespace std;

class MyCalendar {
public:
    MyCalendar() {}

    struct TreeNode {
        pair<int, int> data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int begin, int end)
            : data({ begin, end }), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;

    TreeNode* insert(TreeNode* current, int begin, int end) {
        if (current == nullptr)
            return new TreeNode(begin, end);

        if (end <= current->data.first)
            current->left = insert(current->left, begin, end);
        else if (begin >= current->data.second)
            current->right = insert(current->right, begin, end);

        return current;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool book(int startTime, int endTime) {

        int count = countNodes(root);

        TreeNode* inserted = insert(root, startTime, endTime);

        int newCount = countNodes(root);

        if (!count)
        {
            root = inserted;
            return true;
        }

        return !(count == newCount);
    }
};
