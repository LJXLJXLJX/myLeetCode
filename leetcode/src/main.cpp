#include <iostream>
#include "124_binary_tree_maximum_path_sum.h"
using namespace std;



void test(){

	TreeNode* root = stringToTreeNode("[1,-2,3]");
	prettyPrintTree(root);
	cout << maxPathSum(root) << endl;;
}




void main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	test();
}


/*
static const int _ = []() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
*/