#pragma once

struct TreeNode
{
	int data;

	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	TreeNode(int data) : data(data) {};
};