#include "binary_tree_level_order_traversal_2.h"


using namespace std;


std::vector<std::vector<int>> levelOrderBottom(TreeNode * root)
{
	if (!root)
		return {};
	queue<vector<TreeNode*>> levelNodes;
	vector<vector<int>> ret;
	levelNodes.push({ root });
	ret.push_back({ root->val });
	vector<TreeNode*> curLevelNodes;
	vector<int> curLevelVals;
	while (!levelNodes.front().empty()) {
		curLevelNodes.clear();
		curLevelVals.clear();
		for (TreeNode* node : levelNodes.front()) {
			if (node->left != nullptr) {
				curLevelNodes.push_back(node->left);
				curLevelVals.push_back(node->left->val);
			}
			if (node->right != nullptr) {
				curLevelNodes.push_back(node->right);
				curLevelVals.push_back(node->right->val);
			}
		}
		levelNodes.push(curLevelNodes);
		levelNodes.pop();
		if (!curLevelVals.empty())
			ret.push_back(curLevelVals);
	}
	for (int i = 0; i < ret.size() / 2; ++i)
		swap(ret[i], ret[ret.size() - 1 - i]);

	return ret;
}
