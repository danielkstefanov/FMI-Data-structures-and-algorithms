#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
using namespace std;

bool isSymmetric(TreeNode* root) {
	areSymmetric(root->left, root->right);
}

bool areSymmetric(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;

	if (!p || !q)
		return false;

	return p->val == q->val && areSymmetric(p->left, q->right) && areSymmetric(p->right, q->left);
}