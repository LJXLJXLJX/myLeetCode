#include "validate_binary_search_tree.h"

using namespace std;



void isValidRecur(TreeNode* curNode, long long upBound, long long lowBound, bool& out) {
	if (out == false)
		return;
	if (curNode == nullptr)
		return;
	if (curNode->val <= lowBound || curNode->val >= upBound) {
		out = false;
		return;
	}
	isValidRecur(curNode->left, curNode->val, lowBound, out);
	isValidRecur(curNode->right, upBound, curNode->val, out);
}

bool isValidBST(TreeNode * root)
{
	bool ret = true;
	isValidRecur(root, LLONG_MAX, LLONG_MIN, ret);
	return ret;
}
