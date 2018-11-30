#include "mysqrt.h"

using namespace std;
//ţ�ٵ�������ⷽ�̵ĸ�
int mySqrt(int x) {
	double ans = x;
	double delta = 0.001;
	while (fabs(pow(ans, 2) - x) > delta) {
		ans = (ans + x / ans) / 2;
	}
	return ans;
}
