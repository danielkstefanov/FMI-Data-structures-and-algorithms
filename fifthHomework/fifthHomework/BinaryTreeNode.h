#pragma once

struct BinaryTreeNode
{
	int data;

	BinaryTreeNode* left = nullptr;
	BinaryTreeNode* right = nullptr;

	BinaryTreeNode(int data) : data(data) {};
};