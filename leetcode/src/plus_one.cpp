#include "plus_one.h"

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int carry = 0;
	++digits.back();
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		digits[i] += carry;
		if (digits[i] == 10)
		{
			carry = 1;
			digits[i] = 0;
		}
		else
		{
			carry = 0;
			break;
		}
	}
	if (carry == 1)
		digits.insert(digits.begin(), 1);
	return digits;
}
