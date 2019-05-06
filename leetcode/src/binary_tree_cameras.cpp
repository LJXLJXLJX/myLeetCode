#include "binary_tree_cameras.h"




void posOrder(TreeNode* root, int& nums, int height)
{
	if (!root)
		return;
	posOrder(root->left, nums, height + 1);
	posOrder(root->right, nums, height + 1);
	if ((root->left && root->left->val == 0) || (root->right && root->right->val == 0)) {
		root->val = 2;
		++nums;
	}
	else if ((root->left && root->left->val == 2) || (root->right && root->right->val == 2)) {
		root->val = 1;
	}
	else if (height == 0)
		nums++;
}

int minCameraCover(TreeNode * root) {
	int nums = 0;
	posOrder(root, nums, 0);
	return nums;
}
