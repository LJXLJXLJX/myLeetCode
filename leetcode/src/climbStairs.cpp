#include "climbStairs.h"

using namespace std;

int climbStairs(int n) {
	vector<int> a(n, 0);
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < n; ++i)
		a[i] = a[i - 1] + a[i - 2];
	return a.back();
}