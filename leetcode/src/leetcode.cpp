#include <iostream>
#include  "merge_sorted_array.h"
using namespace std;



void test()
{
	vector<int>a{ 1, 2, 3, 0, 0, 0 };
	vector<int>b{ 2,5,6 };
	merge(a, 3, b, 3);
	for (int i : a)
		cout << i << " ";
	cout << endl;
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