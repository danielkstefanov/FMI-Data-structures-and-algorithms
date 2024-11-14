#include <vector>
#include <queue>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> answer;

		if (!root)
			return answer;

		queue<TreeNode*> levels;
		levels.push(root);

		while (!levels.empty()) {

			int currentLevelSize = levels.size();

			vector<int> currentLevel;
			for (int i = 0; i < currentLevelSize; i++) {
				TreeNode* node = levels.front();

				if (node->left)
					levels.push(node->left);

				if (node->right)
					levels.push(node->right);

				currentLevel.push_back(node->val);
				levels.pop();
			}

			answer.push_back(currentLevel);
		}

		return answer;
	}
};