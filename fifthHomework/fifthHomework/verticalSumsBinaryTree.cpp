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

void sumVerticalsInDeque(const BinaryTreeNode* current, deque<long>& verticalSums, int& mid, int awayFromVertical)
{
	if (current != nullptr)
	{
		if (verticalSums.size() == 0)
		{
			verticalSums.push_back(current->data);
		}
		else
		{
			if (mid + awayFromVertical < 0)
			{
				verticalSums.push_front(current->data);
				mid++;
			}
			else if (mid + awayFromVertical >= verticalSums.size())
			{
				verticalSums.push_back(current->data);
			}
			else
			{
				verticalSums[mid + awayFromVertical] += current->data;
			}
		}

		sumVerticalsInDeque(current->left, verticalSums, mid, awayFromVertical - 1);

		sumVerticalsInDeque(current->right, verticalSums, mid, awayFromVertical + 1);
	}
}


void printVerticalSumsOfBinaryTree()
{
	size_t n;
	cin >> n;

	vector<tuple<int, int, int>> triplets;

	for (size_t i = 0; i < n; i++)
	{
		int index;
		int leftIndex;
		int rightIndex;
		cin >> index >> leftIndex >> rightIndex;
		triplets.emplace_back(index, leftIndex, rightIndex);
	}

	BinaryTreeNode* root = createTree(triplets);

	deque<long> verticalSums;
	int mid = 0;
	sumVerticalsInDeque(root, verticalSums, mid, 0);

	while (verticalSums.size())
	{
		if (verticalSums.front() != 0)
			cout << verticalSums.front() << " ";

		verticalSums.pop_front();
	}
}