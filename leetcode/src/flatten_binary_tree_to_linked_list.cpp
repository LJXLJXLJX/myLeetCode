//
// Created by ljx on 1/18/19.
//

#include "flatten_binary_tree_to_linked_list.h"


void flattenRecur(TreeNode *&node) {
    if(!node)
        return;
    flattenRecur(node->left);
    TreeNode* tmpR=node->right;
    if(node->left){
        TreeNode* lh=node->left;
        TreeNode*lt=lh;
        while(lt->right)
            lt=lt->right;
        node->right=lh;
        node->left=nullptr;
        lt->right=tmpR;
    }
    flattenRecur(tmpR);
}

void flatten(TreeNode *root) {
    flattenRecur(root);
}
