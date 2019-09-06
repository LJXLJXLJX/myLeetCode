#include "662_maximum_width_of_binary_tree.h"

using namespace std;


int dfs(TreeNode* root, int level, int order, vector<pair<int, int>>& vec) {
	if (root == nullptr)return 0;
	if (vec.size() == level)vec.push_back({ order, order });
	else vec[level].second = order;
	return max({ vec[level].second - vec[level].first + 1, dfs(root->left, level + 1, 2 * order, vec), dfs(root->right, level + 1, 2 * order + 1, vec) });
}


int widthOfBinaryTree(TreeNode * root) {
	return dfs(root, 0, 1, vector<pair<int, int>>() = {});
}


//低效解法 不好
//int widthOfBinaryTree(TreeNode * root)
//{
//	if (root == nullptr)
//		return 0;
//	list<TreeNode*> lst{ root };
//	list<TreeNode*> lst1;
//	int ret = 0;
//
//	int left = -1;
//	int right = -1;
//	bool has_left = false;
//	int pos = -1;
//	while (!lst.empty()) {
//		pos++;
//		if (lst.front() == nullptr) {
//			if (has_left)
//			{
//				lst1.push_back(nullptr);
//				lst1.push_back(nullptr);
//			}
//		}
//		else {
//			lst1.push_back(lst.front()->left);
//			lst1.push_back(lst.front()->right);
//			if (!has_left) {
//				left = pos;
//				has_left = true;
//			}
//			right = pos;
//		}
//		lst.pop_front();
//		if (lst.empty())
//		{
//			swap(lst, lst1);
//			lst1.clear();
//			while (lst.size()>0 && lst.back() == nullptr)
//				lst.pop_back();
//
//			ret = max(ret, right - left + 1);
//			left = right = -1;
//			has_left = false;
//			pos = -1;
//		}
//	}
//	return ret;
//}
