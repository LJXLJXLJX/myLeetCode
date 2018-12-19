#include "binary_tree_inorder_traversal.h"


using namespace std;


void inorderTraversalRecur(TreeNode *curRoot, std::vector<int>& out)
{
	if (curRoot->left != nullptr)
		inorderTraversalRecur(curRoot->left, out);
	out.push_back(curRoot->val);
	if (curRoot->right != nullptr)
		inorderTraversalRecur(curRoot->right, out);
}

std::vector<int> inorderTraversal(TreeNode * root)
{
	if (root == nullptr)
		return std::vector<int>();
	std::vector<int> ret;
	inorderTraversalRecur(root, ret);
	return ret;
}
