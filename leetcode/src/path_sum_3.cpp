//
// Created by ljx on 1/22/19.
//

#include "path_sum_3.h"

using namespace std;


int helper(TreeNode *node, int curSum, int &sum) {
    if (!node) return 0;
    curSum += node->val;
    return (curSum == sum) + helper(node->left, curSum, sum) + helper(node->right, curSum, sum);
}


int pathSum3(TreeNode *root, int sum) {
    if(!root)
        return 0;
    return helper(root,0,sum)+pathSum3(root->left,sum)+pathSum3(root->right,sum);
}
