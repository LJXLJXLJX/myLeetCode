
#include <iostream>
#include "flip_binary_tree_to_match_preorder_traversal.h"
using namespace std;



void test()
{
    TreeNode* root= stringToTreeNode("[1,2]");
    vector<int> voyage{2,1};
    flipMatchVoyage(root,voyage);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	test();
	return 0;
}


/*
static const int _ = []() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
*/