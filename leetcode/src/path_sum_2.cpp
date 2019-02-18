#include "path_sum_2.h"

using namespace std;

void helper(TreeNode*& curNode, int curSum, int sum, vector<int>& vec, vector<vector<int>>& out) {
	vec.push_back(curNode->val);
	curSum += curNode->val;

	if (!(curNode->left || curNode->right)) {
		if (curSum == sum) {
			out.push_back(vec);
		}
		vec.pop_back();
		return;
	}
	if (curNode->left) {
		helper(curNode->left, curSum, sum, vec, out);
	}
	if (curNode->right) {
		helper(curNode->right, curSum, sum, vec, out);
	}
	vec.pop_back();
}


std::vector<std::vector<int>> pathSum2(TreeNode * root, int sum)
{
	if (!root)
		return{};
	vector<int> vec;
	vector<vector<int>> out;
	helper(root, 0, sum, vec, out);
	return out;
}
