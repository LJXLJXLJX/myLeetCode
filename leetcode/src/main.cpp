#include <iostream>
#include "207_course_schedule.h"

using namespace std;



void test() {
	vector<vector<int>> prerequisites{ {1,0},{0,1} };

	cout << canFinish(2, prerequisites) << endl;
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