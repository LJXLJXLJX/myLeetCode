#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"

using namespace std;


void buildTreeRecur(TreeNode*& curNode, std::vector<int>& preorder, vector<int>& inorder, int preorderHead, int preorderTail, int  inorderHead, int inorderTail)
{
	if (preorderHead == preorderTail || inorderHead == inorderTail)
		return;
	curNode = new TreeNode(preorder[preorderHead]);
	int count = find(inorder.begin() + inorderHead, inorder.end(), curNode->val) - (inorder.begin() + inorderHead);
	buildTreeRecur(curNode->left, preorder, inorder, preorderHead + 1, preorderHead + 1 + count, inorderHead, inorderHead + count);
	buildTreeRecur(curNode->right, preorder, inorder, preorderHead + count + 1, preorderTail, inorderHead + count + 1, inorderTail);
}

TreeNode * buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
	TreeNode* root = nullptr;
	buildTreeRecur(root, preorder, inorder, 0, preorder.size(), 0, inorder.size());
	return root;
}
