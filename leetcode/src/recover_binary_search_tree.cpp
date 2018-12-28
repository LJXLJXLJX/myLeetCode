#include "recover_binary_search_tree.h"

using namespace std;



/*
BST的中序遍历序列是一个递增序列，利用这一点，这题就很好解决了
*/

void recover(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b) {
	if (root) {
		recover(root->left, pre, a, b);
		if (root->val < pre->val) {
			if (!a) a = pre; //a should change once.
			b = root; //b could change twice.
		}
		pre = root;
		recover(root->right, pre, a, b);
	}
}
void recoverTree(TreeNode *root) {
	if (!root) return;
	TreeNode p(INT_MIN);
	TreeNode *a, *b, *pre;
	a = b = 0;
	pre = &p;
	recover(root, pre, a, b);
	if (a && b)
		swap(a->val, b->val);
	return;
}