#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"

using namespace std;

void buildTree2Recur(TreeNode*& curNode, std::vector<int>& inorder, std::vector<int>& postorder, int ih, int it, int ph, int pt)
{
	if (ih == it || ph == pt) return;
	curNode = new TreeNode(postorder[pt - 1]);
	int leftLen = 0;
	for (int i = ih; i < it; i++) {
		if (inorder[i] == curNode->val)
			break;
		leftLen++;
	}
	buildTree2Recur(curNode->left, inorder, postorder, ih, ih + leftLen, ph, ph + leftLen);
	buildTree2Recur(curNode->right, inorder, postorder, ih + leftLen + 1, it, ph + leftLen, pt - 1);
}

TreeNode * buildTree2(std::vector<int>& inorder, std::vector<int>& postorder)
{
	TreeNode* root = nullptr;
	buildTree2Recur(root, inorder, postorder, 0, inorder.size(), 0, postorder.size());
	return root;
}

