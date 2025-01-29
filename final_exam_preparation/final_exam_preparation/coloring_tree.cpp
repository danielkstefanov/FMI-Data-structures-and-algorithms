#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode 
{
	int index = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode* parent = nullptr;
};

bool has_uncolored_kid(TreeNode*& current, vector<bool>& colored)
{
	if (!current)
		return false;

	if (current->left && !colored[current->left->index])
		return true;

	if (current->right && !colored[current->right->index])
		return true;

	return false;
}

void dfs(TreeNode* current, int& result, vector<bool>& colored) 
{
	if (current == nullptr)
		return;

	dfs(current->left, result, colored);
	dfs(current->right, result, colored);

	if (has_uncolored_kid(current, colored))
	{
		colored[current->index] = true;

		if (current->left)
			colored[current->left->index] = true;
		if (current->right)
			colored[current->right->index] = true;
		if (current->parent)
			colored[current->parent->index] = true;

		result++;
	}
}

int main() 
{
	int nodes_count, left, right; 
	cin >> nodes_count;

	vector<TreeNode*> nodes(nodes_count);
	for (size_t i = 0; i < nodes_count; i++)
	{
		nodes[i] = new TreeNode();
	}

	for (size_t i = 0; i < nodes_count; i++)
	{
		cin >> left >> right;
		nodes[i]->index = i;
		if (left != -1)
		{
			nodes[i]->left = nodes[left];
			nodes[left]->parent = nodes[i];
		}
		if (right != -1)
		{
			nodes[i]->right = nodes[right];
			nodes[right]->parent = nodes[i];
		}

	}

	int result = 0;
	vector<bool> colored(nodes_count, false);
	dfs(nodes[0],result, colored);

	if (!colored[0])
		result++;
	cout << result;
}