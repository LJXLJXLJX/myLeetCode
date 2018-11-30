#include "mysqrt.h"

using namespace std;
//牛顿迭代法求解方程的根
int mySqrt(int x) {
	double ans = x;
	double delta = 0.001;
	while (fabs(pow(ans, 2) - x) > delta) {
		ans = (ans + x / ans) / 2;
	}
	return ans;
}
