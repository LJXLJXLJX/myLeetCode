#include "isPalindrome.h"

bool isPalindrome(int x)
{
	if (x == 0)
		return true;
	if (x < 0 || (x != 0 && x % 10 == 0))
		return false;
	int originX = x;
	int xReverse = 0;
	int digit = 0;
	while (x != 0)
	{
		if (xReverse == x || x / 10 == xReverse)
			return true;
		digit = x % 10;
		xReverse = xReverse * 10 + digit;
		x /= 10;
	}
	return false;
}
