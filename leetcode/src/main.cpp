#include <iostream>
#include "377_combination_sum_IV.h"

using namespace std;



void test() {

	vector<int> nums{ 3,4,5,6,7,8,9,10};
	int target = 10;
	cout<<combinationSum4(nums, target) << endl;
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