#include "minimum_depth_of_binary_tree.h"


using namespace std;


int minDepth(TreeNode * root)
{
	if (root == nullptr)
		return 0;
	queue<vector<TreeNode*>> nodesQueue;
	nodesQueue.push({ root });
	int depth = 1;
	while (!nodesQueue.front().empty()) {
		vector<TreeNode*> tmpVec;
		for (TreeNode* node : nodesQueue.front()) {
			if (!(node->left || node->right)) return depth;
			if (node->left) tmpVec.push_back(node->left);
			if (node->right)tmpVec.push_back(node->right);
		}
		nodesQueue.push(tmpVec);
		nodesQueue.pop();
		depth++;
	}
	return depth;
}
