#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <deque>

using namespace std;

struct TreeNode
{
    int index;

    vector<TreeNode*> children;

    TreeNode(int index) :index(index), children() {};
};

TreeNode* findNodeByIndex(TreeNode* current, int index)
{
    if (current != nullptr)
    {
        if (current->index == index)
            return current;

        for (size_t i = 0; i < current->children.size(); i++)
        {
            TreeNode* currentNode = findNodeByIndex(current->children[i], index);
            if (currentNode)
                return currentNode;
        }

        return nullptr;
    }

    return nullptr;
}


bool areRelated(TreeNode* current, int leftIndex, int rightIndex)
{
    if (leftIndex == rightIndex)
        return true;

    if (leftIndex > rightIndex)
        return false;

    TreeNode* leftNode = findNodeByIndex(current, leftIndex);
    if (leftNode)
    {
        if (findNodeByIndex(leftNode, rightIndex))
            return true;
    }

    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    size_t n;
    cin >> n;

    TreeNode** nodes = new TreeNode*[n];

    for (size_t i = 0; i < n; i++)
    {
        nodes[i] = new TreeNode(i);
    }

    for (size_t j = 0; j < n - 1; ++j)
    {
        int left, right;
        cin >> left >> right;

        nodes[left]->children.push_back(nodes[right]);
    }

    int q;
    cin >> q;

    for (size_t i = 0; i < q; ++i)
    {
        int leftIndex, rightIndex;
        cin >> leftIndex >> rightIndex;

        cout << (areRelated(nodes[0], leftIndex, rightIndex) ? "YES" : "NO") << endl;
    }

    return 0;
}