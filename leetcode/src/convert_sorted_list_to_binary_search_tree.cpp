#include "convert_sorted_list_to_binary_search_tree.h"


ListNode* list = nullptr;


int count(ListNode* node) {
	int ret = 0;
	while (node) {
		ret++;
		node = node->next;
	}
	return ret;
}

TreeNode* generate(int n) {
	if (n == 0)
		return nullptr;
	TreeNode* node = new TreeNode(0);
	node->left = generate(n / 2);
	node->val = list->val;
	list = list->next;
	node->right = generate(n - n / 2 - 1);
	return node;
}

TreeNode * sortedListToBST(ListNode * head)
{
	list = head;
	return generate(count(list));
}
