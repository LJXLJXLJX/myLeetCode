#include <iostream>
#include "convert_sorted_array_to_binary_search_tree.h"
using namespace std;



void test()
{
	vector<int> nums = { -10,-3,0,5,9 };
	TreeNode* root = sortedArrayToBST(nums);
	prettyPrintTree(root);
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