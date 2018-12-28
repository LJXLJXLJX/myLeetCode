#include "binary_tree_level_order_traversal.h"

using namespace std;



std::vector<std::vector<int>> levelOrder(TreeNode * root)
{
	if (root == nullptr)
		return {};
	vector<vector<TreeNode*>> levels{ {root} };
	vector<vector<int>> ret{ {root->val} };
	int level = 0;
	while (level < levels.size()) {
		vector<TreeNode*> nextLevel;
		vector<int> nextLevelVal;
		for (TreeNode* node : levels[level]) {
			if (node->left) {
				nextLevel.push_back(node->left);
				nextLevelVal.push_back(node->left->val);
			}
			if (node->right) {
				nextLevel.push_back(node->right);
				nextLevelVal.push_back(node->right->val);
			}
		}
		if (!nextLevel.empty()) {
			levels.push_back(nextLevel);
			ret.push_back(nextLevelVal);
		}
		level++;
	}
	return ret;
}
