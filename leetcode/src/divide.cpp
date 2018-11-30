#include "divide.h"
#include "heads.h"


using namespace std;

int divide(int dividend, int divisor)
{
	long long res = 0;
	if (divisor == 0)
		return INT_MAX;
	long long dd = llabs(dividend);
	long long ds = llabs(divisor);

	long long originDs = ds;
	int sign = 0;
	if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
		sign = 1;
	else
		sign = -1;
	int offset = -1;
	while (offset != 0)
	{
		offset = 0;
		ds = originDs;
		while (dd >= (ds << 1))
		{
			ds <<= 1;	//左移一位 相当于乘以二
			offset++;
		}
		if (dd < ds)
			break;
		else
			dd -= ds;
		res += (1ll << offset);
	}
	res = res * sign;
	return (res > INT_MAX || res < INT_MIN) ? INT_MAX : (int)res;
}
