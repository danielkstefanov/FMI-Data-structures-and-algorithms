#include <iostream>
#include <vector>
#include <map>
#include "KeyValueTreeNode.h"
using namespace std;


KeyValueTreeNode* insert(KeyValueTreeNode* current, int key, int value)
{
	if (current == nullptr)
		return new KeyValueTreeNode(key, value);

	if (key == current->key)
	{
		current->value += value;
	}
	else 
	{
	if (key < current->key)
		current->left = insert(current->left, key, value);
	else if (key > current->key)
		current->right = insert(current->right, key, value);
	}

	return current;
}

void traverse(KeyValueTreeNode* current, vector<vector<int>>& answer) 
{
	if (current != nullptr)
	{
		traverse(current->left, answer);
		answer.push_back({current->key, current->value});
		traverse(current->right, answer);
	}
}

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

	KeyValueTreeNode* root = new KeyValueTreeNode(items1[0][0], items1[0][1]);

	for (size_t i = 1; i < items1.size(); i++)
		insert(root, items1[i][0], items1[i][1]);

	for (size_t i = 0; i < items2.size(); i++)
		insert(root, items2[i][0], items1[i][1]);

	vector<vector<int>> answer;

	traverse(root, answer);

	return answer;
}

vector<vector<int>> mergeSimilarItemsWithMap(vector<vector<int>>& items1, vector<vector<int>>& items2) {
	map<int, int> weightMap;

	for (const auto& item : items1) {
		int value = item[0];
		int weight = item[1];
		weightMap[value] += weight;
	}

	for (const auto& item : items2) {
		int value = item[0];
		int weight = item[1];
		weightMap[value] += weight;
	}

	vector<vector<int>> result;

	for (const auto& current : weightMap) {
		result.push_back({ current.first, current.second });
	}

	return result;
}
