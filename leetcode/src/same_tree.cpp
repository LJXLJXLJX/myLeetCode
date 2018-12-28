#include "same_tree.h"

void isSameRecur(TreeNode* curNode1, TreeNode* curNode2, bool& out) {
	if (out == false)
		return;
	if ((curNode1 == nullptr &&curNode2 != nullptr) || (curNode1 != nullptr && curNode2 == nullptr)) {
		out = false;
		return;
	}
	if (curNode1 == nullptr && curNode2 == nullptr)
		return;
	if (curNode1->val != curNode2->val) {
		out = false;
		return;
	}
	isSameRecur(curNode1->left, curNode2->left, out);
	isSameRecur(curNode1->right, curNode2->right, out);
}

bool isSameTree(TreeNode * p, TreeNode * q)
{
	bool ret = true;
	isSameRecur(p, q, ret);
	return ret;
}
