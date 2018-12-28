#include "symmetric_tree.h"

using namespace std;

bool isSymmerticRecur(TreeNode* node1, TreeNode* node2) {
	if (!(node1||node2))
		return true;
	else if (!(node1 && node2)) 
		return  false;
	else if (node1->val != node2->val)
		return false;
	return  isSymmerticRecur(node1->left, node2->right) && isSymmerticRecur(node1->right, node2->left);
}

bool isSymmetric(TreeNode * root)
{
	return isSymmerticRecur(root, root);
}
