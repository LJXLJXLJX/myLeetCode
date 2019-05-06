#include "116_populating_next_right_pointers_in_each_Node.h"


using namespace std;



/*
TreeNode * connect(TreeNode * root)
{
	if (root == nullptr)
		return root;
	queue<vector<TreeNode*>> layers;
	layers.push({ root });
	int layerNum = -1;
	while (!layers.empty()) {
		vector<TreeNode*> nextLayer;
		for (int index = 0; index < layers.front().size(); ++index) {
			if (index == layers.front().size()-1)
				layers.front()[index]->next = nullptr;
			else 
				layers.front()[index]->next = layers.front()[index + 1];
			
			if (layers.front()[index]->left != nullptr) {
				nextLayer.push_back(layers.front()[index]->left);
				nextLayer.push_back(layers.front()[index]->right);
			}
		}
		layers.pop();
		if (!nextLayer.empty())
			layers.push(nextLayer);
	}
	return root;
}
*/


TreeNode * connect(TreeNode * root)
{
	if (!root) {
		return NULL;
	}
	if (root->left) {
		root->left->next = root->right;
		if (root->next) {
			root->right->next = root->next->left;
		}
		connect(root->left);
		connect(root->right);
	}
	return root;
}