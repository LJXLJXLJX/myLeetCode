#include "reverse.h"

using namespace std;

int reverse(int x)
{
	vector<int> num({});
	int sign = 1;
	int absX = abs(x);
	if (x < 0)
		sign = -1;
	else
		sign = 1;
	while (1)
	{
		if (absX == 0)
			break;
		num.push_back(absX % 10);
		absX = absX / 10;
	}
	long long mutiple = 1;
	long long result = 0;
	unsigned int digit = 0;
	while (!num.empty())
	{
		digit = num.back();
		num.pop_back();
		long long temp = digit * mutiple;
		result += digit * mutiple;
		mutiple *= 10;
	}
	result = result * sign;
	return result <= INT_MAX && result >= INT_MIN ? result : 0;
}
