#include <iostream>
#include "interleaving_string.h"
using namespace std;



void test()
{	
	string s1 = "bab";
	string s2 = "abbbcba";
	string s3 = "babbbabcba";
	cout << isInterleave(s1, s2, s3) << endl;
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