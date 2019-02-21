#include <iostream>
#include "construct_string_from_binary_tree.h"
using namespace std;



void test()
{
	TreeNode* t = stringToTreeNode("[1,2,3,4]");
	
	prettyPrintTree(t);


	cout << tree2str(t) << endl;
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