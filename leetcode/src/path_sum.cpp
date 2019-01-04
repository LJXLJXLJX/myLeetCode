#include "path_sum.h"


using namespace std;


void hasPathSumRecur(TreeNode* curNode, int sum, bool &out) {
	if (out || !curNode) return;
	if ( !(curNode->left || curNode->right) && curNode->val == sum) {
		out = true;
		return;
	}
	if (curNode->left) {
		curNode->left->val += curNode->val;
		hasPathSumRecur(curNode->left, sum, out);
	}
	if (curNode->right) {
		curNode->right->val += curNode->val;
		hasPathSumRecur(curNode->right, sum, out);
	}
}

bool hasPathSum(TreeNode * root, int sum)
{
	bool ret = false;
	hasPathSumRecur(root, sum, ret);
	return ret;
}
