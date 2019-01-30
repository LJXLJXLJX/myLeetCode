
#include <iostream>
#include "string_without_AAA_or_BBB.h"
using namespace std;



void test()
{
    cout<<strWithout3a3b(4,1)<<endl;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	test();
	return 0;
}


/*
static const int _ = []() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
*/