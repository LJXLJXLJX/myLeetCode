#include <iostream>
#include "392_is_subsequence.h"
using namespace std;



void test() {

	string s = "abc";
	string t = "ahbgdc";
	cout << isSubsequence(s, t) << endl;;
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