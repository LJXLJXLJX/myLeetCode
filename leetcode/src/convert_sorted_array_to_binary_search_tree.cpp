#include "convert_sorted_array_to_binary_search_tree.h"


using namespace std;

void sortedArrayToBSTRecur(std::vector<int>& nums, TreeNode*& curNode, int head, int tail) {
	if (head == tail)
		return;
	int mid = (tail + head) / 2;
	curNode = new TreeNode(nums[mid]);
	sortedArrayToBSTRecur(nums, curNode->left, head, mid);
	sortedArrayToBSTRecur(nums, curNode->right, mid+1, tail);
}

TreeNode * sortedArrayToBST(std::vector<int>& nums)
{
	TreeNode* root = nullptr;
	sortedArrayToBSTRecur(nums, root, 0, nums.size());
	return root;
}
