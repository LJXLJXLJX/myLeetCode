#include "balanced_binary_tree.h"


#define NOMINMAX

//自顶向下的就不多说了
//直接自底向上

using namespace std;

int getHeight(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int left = getHeight(root->left);
	if (left == -1)
		return -1;
	int right = getHeight(root->right);
	if (right == -1)
		return -1;
	if (abs(left - right) > 1)
		return -1;

	return std::max(left, right) + 1;
}


bool isBalanced(TreeNode * root)
{
	return getHeight(root) != -1;
}
