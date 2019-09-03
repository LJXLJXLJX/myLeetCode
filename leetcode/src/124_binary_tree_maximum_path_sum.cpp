#include "124_binary_tree_maximum_path_sum.h"

using namespace std;


int maxPathFromCurToLeaf(TreeNode* cur,int& ret) {
	if (cur == nullptr)
		return 0;

	int left_sum = maxPathFromCurToLeaf(cur->left,ret);
	int right_sum = maxPathFromCurToLeaf(cur->right,ret);
	if (left_sum < 0)left_sum = 0;
	if (right_sum < 0)right_sum = 0;
	if (cur->val + left_sum + right_sum > ret)ret = cur->val + left_sum + right_sum;
	return cur->val + max(left_sum, right_sum);
}

int maxPathSum(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	int ret = 0;
	maxPathFromCurToLeaf(root, ret);
	return ret;
}

