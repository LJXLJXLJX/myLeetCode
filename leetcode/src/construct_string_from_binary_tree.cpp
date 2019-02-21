#include "construct_string_from_binary_tree.h"


using namespace std;

std::string tree2str(TreeNode * t)
{
	string nodeStr;
	if (t == nullptr)
		return "";
	else
		nodeStr = to_string(t->val);
	if (!t->left && !t->right)
		return nodeStr;
	else if (t->left && !t->right)
		return nodeStr + "(" + tree2str(t->left) + ")";
	else if (!t->left && t->right)
		return nodeStr + "()" + "(" + tree2str(t->right) + ")";
	else
		return nodeStr + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
}
