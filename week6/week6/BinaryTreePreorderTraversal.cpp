#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:

	void preorderTraversalRecursive(vector<int>& elements, TreeNode* root)
	{
		if (root != nullptr)
		{
			elements.push_back(root->val);

			preorderTraversalRecursive(elements, root->left);
			preorderTraversalRecursive(elements, root->right);
		}
	}

	vector<int> preorderTraversalIterative(TreeNode* root) {
		vector<int> answer;

		if (!root)
			return answer;

		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty()) {

			TreeNode* node = st.top();
			st.pop();
			answer.push_back(node->val);

			if (node->right)
				st.push(node->right);

			if (node->left)
				st.push(node->left);
		}

		return answer;
	}

	vector<int> preorderTraversal(TreeNode* root, bool withRecursion) {


		if (withRecursion)
		{
			vector<int> answer;
			preorderTraversalRecursive(answer, root);
			return answer;
		}
		else
		{
			return preorderTraversalIterative(root);
		}

	}
};