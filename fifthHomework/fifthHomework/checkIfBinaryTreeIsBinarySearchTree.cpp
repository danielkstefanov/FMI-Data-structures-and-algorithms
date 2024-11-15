#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <deque>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode* createTree(vector<tuple<int, int, int>>& triplets)
{
	BinaryTreeNode** nodesArray = new BinaryTreeNode * [triplets.size()];

	for (size_t i = 0; i < triplets.size(); i++)
		nodesArray[i] = new BinaryTreeNode(get<0>(triplets[i]));

	for (size_t i = 0; i < triplets.size(); i++)
	{
		int currentLeftIndex = get<1>(triplets[i]);
		int currentRightIndex = get<2>(triplets[i]);

		if (currentLeftIndex != -1 && nodesArray[i]->left == nullptr && currentLeftIndex < int(triplets.size()))
			nodesArray[i]->left = nodesArray[currentLeftIndex];

		if (currentRightIndex != -1 && nodesArray[i]->right == nullptr && currentRightIndex < int(triplets.size()))
			nodesArray[i]->right = nodesArray[currentRightIndex];
	}

	return nodesArray[0];
}

bool isBinaryTree(const BinaryTreeNode* current, int*& last)
{
	if (current != nullptr)
	{
		bool isLeftBinaryTree = isBinaryTree(current->left, last);

		if (!last)
			last = new int(current->data);
		if (*last > current->data)
			return false;
		else
			last = new int(current->data);

		bool isRightBinaryTree = isBinaryTree(current->right, last);

		return isLeftBinaryTree && isRightBinaryTree;
	}
	else
	{
		return true;
	}
}


void checkIfBinaryTreeIsBinarySearchTree()
{
	size_t n;
	cin >> n;

	for (size_t j = 0; j < n; j++)
	{
		int currentTreeNodesCount;
		cin >> currentTreeNodesCount;

		vector<tuple<int, int, int>> triplets;

		for (size_t i = 0; i < currentTreeNodesCount; i++)
		{
			int index;
			int leftIndex;
			int rightIndex;
			cin >> index >> leftIndex >> rightIndex;
			triplets.emplace_back(index, leftIndex, rightIndex);
		}

		BinaryTreeNode* root = createTree(triplets);
		int* last = nullptr;
		std::cout << isBinaryTree(root, last) << endl;
	}
}