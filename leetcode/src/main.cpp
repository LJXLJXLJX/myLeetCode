#include <iostream>
#include "128_longest_consecutive_sequence.h"

using namespace std;



void test() {
	vector<int> arr{ 100, 4, 200, 1, 3, 2 };
	cout << longestConsecutive(arr) << endl;
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