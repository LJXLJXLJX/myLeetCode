#include <iostream>
#include "minimum_depth_of_binary_tree.h"
using namespace std;



void test()
{
	TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]");

	cout << minDepth(root) << endl;
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