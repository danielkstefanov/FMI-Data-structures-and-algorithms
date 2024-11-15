#pragma once
#include <vector>

using namespace std;

struct TreeNode
{
    int index;

    vector<TreeNode*> children;

    TreeNode(int index) :index(index) {};
};