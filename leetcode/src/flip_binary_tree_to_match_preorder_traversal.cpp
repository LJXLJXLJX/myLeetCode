//
// Created by ljx on 1/22/19.
//

#include "flip_binary_tree_to_match_preorder_traversal.h"

using namespace std;

void dfs(TreeNode *node, std::vector<int> &voyage, int &index, vector<int> &nums) {
    if (nums == vector<int>({-1}))
        return;
    if (node->val != voyage[index]) {
        nums = {-1};
        return;
    }
    if (node->left && node->right) {
        if (node->left->val != voyage[index + 1]) {
            swap(node->left, node->right);
            nums.push_back(node->val);
        }
        dfs(node->left, voyage, ++index, nums);
        dfs(node->right, voyage, ++index, nums);
    } else if (node->left && !node->right) {
        dfs(node->left, voyage, ++index, nums);
    } else if (!node->left && node->right) {
        dfs(node->right, voyage, ++index, nums);
    }
}

std::vector<int> flipMatchVoyage(TreeNode *root, std::vector<int> &voyage) {
    int index = 0;
    vector<int> nums;
    dfs(root, voyage, index, nums);
    return nums;
}
