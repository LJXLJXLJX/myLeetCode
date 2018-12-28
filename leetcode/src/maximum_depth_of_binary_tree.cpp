#include "maximum_depth_of_binary_tree.h"

using namespace std;

void maxDepthRecur(TreeNode* curNode, int curDepth, int& maxDepth) {
	if (curDepth > maxDepth)
		maxDepth = curDepth;
	if (!(curNode->left || curNode->right))
		return;
	if (curNode->left)
		maxDepthRecur(curNode->left, curDepth + 1, maxDepth);
	if (curNode->right)
		maxDepthRecur(curNode->right, curDepth + 1, maxDepth);
}

int maxDepth(TreeNode * root)
{
	if (!root)
		return 0;
	int maxDepth = 1;
	maxDepthRecur(root, 1, maxDepth);
	return maxDepth;
}
