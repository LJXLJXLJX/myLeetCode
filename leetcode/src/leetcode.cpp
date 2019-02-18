#include <iostream>
#include "path_sum_2.h"
using namespace std;



void test()
{
	TreeNode* root = stringToTreeNode("[-2,null,-3]");
	auto ret=pathSum2(root, -5);
	for (auto vec : ret) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
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