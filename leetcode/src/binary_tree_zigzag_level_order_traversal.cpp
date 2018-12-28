#include "binary_tree_zigzag_level_order_traversal.h"

using namespace std;

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode * root)
{
	if (root == nullptr)
		return {};
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	vector<vector<int>> ret;
	vector<int> tmp;
	s1.push(root);
	bool end = false;

	while (!(s1.empty() && s2.empty())) {
		while (!s1.empty()) {
			if (s1.top()->left != nullptr) {
				s2.push(s1.top()->left);
			}
			if (s1.top()->right != nullptr) {
				s2.push(s1.top()->right);
			}
			tmp.push_back(s1.top()->val);
			s1.pop();
		}
		if (!tmp.empty()) {
			ret.push_back(tmp);
			tmp.clear();
		}
		while (!s2.empty()) {
			if (s2.top()->right != nullptr) {
				s1.push(s2.top()->right);
			}
			if (s2.top()->left != nullptr) {
				s1.push(s2.top()->left);
			}
			tmp.push_back(s2.top()->val);
			s2.pop();
		}
		if (!tmp.empty()) {
			ret.push_back(tmp);
			tmp.clear();
		}
	}
	return ret;
}
