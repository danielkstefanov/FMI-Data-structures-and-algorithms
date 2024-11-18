#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
using namespace std;

TreeNode* smallestElementOfTree(TreeNode* root)
{
    if (!root)
        return nullptr;

    while (root->left)
        root = root->left;

    return root;
}

TreeNode* deleteNode(TreeNode* current, int key) {
    if (!current)
        return nullptr;

    if (key < current->val) 
    {
        current->left = deleteNode(current->left, key);
    }
    else if (key > current->val)
    {
        current->right = deleteNode(current->right, key);
    }
    else 
    {
        if (!current->left)
            return current->right;

        if (!current->right)
            return current->left;

        TreeNode* nextSmallest = smallestElementOfTree(current->right);
        swap(nextSmallest->val,current->val);

        current->right = deleteNode(current->right, key);
    }

    return current;
}