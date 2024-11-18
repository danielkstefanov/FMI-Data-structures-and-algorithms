#pragma once

struct KeyValueTreeNode
{
	int key;
	int value;

	KeyValueTreeNode* left;
	KeyValueTreeNode* right;
	KeyValueTreeNode() : key(0), value(0), left(nullptr), right(nullptr) {}
	KeyValueTreeNode(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {}
	KeyValueTreeNode(int key, int value, KeyValueTreeNode* left, KeyValueTreeNode* right) : key(key), value(value), left(left), right(right) {}
};