#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

void traverseAndSaveTimes(TreeNode* current, vector<pair<int, int>>& traversalTimes, int& currentTime)
{
    traversalTimes[current->index].first = currentTime++;

    for (TreeNode* child : current->children)
        traverseAndSaveTimes(child, traversalTimes, currentTime);

    traversalTimes[current->index].second = currentTime++;
}

void IsThereAPathBetweenTwoNodes()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<TreeNode*> nodes(n);

    for (size_t i = 0; i < n; i++)
        nodes[i] = new TreeNode(i);

    for (size_t j = 0; j < n - 1; ++j)
    {
        int left, right;
        cin >> left >> right;

        nodes[left]->children.push_back(nodes[right]);
    }

    vector<pair<int, int>> traversalTimes(n);

    int currentTime = 1;

    traverseAndSaveTimes(nodes[0], traversalTimes, currentTime);

    int q;
    cin >> q;

    for (size_t i = 0; i < q; ++i)
    {
        int leftIndex, rightIndex;
        cin >> leftIndex >> rightIndex;

        bool areRelated = traversalTimes[leftIndex].first <= traversalTimes[rightIndex].first && traversalTimes[leftIndex].second >= traversalTimes[rightIndex].second;
        cout << ((areRelated) ? "YES" : "NO") << '\n';
    }

    for (int i = 0; i < n; ++i)
        delete nodes[i];
}