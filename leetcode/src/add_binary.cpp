#include "add_binary.h"

using namespace std;

string addBinary(string a, string b) {
	int len = max(a.size(), b.size());
	a = string(len - a.size(), '0') + a;
	b = string(len - b.size(), '0') + b;
	string res;
	char carry = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		char digitA = a[i] - '0';
		char digitB = b[i] - '0';
		char digitRes = digitA + digitB + carry;
		if (digitRes > 1)
		{
			carry = 1;
			digitRes %= 2;
		}
		else
			carry = 0;
		digitRes += '0';
		res = digitRes + res;
	}
	if (carry == 1)
		res = "1" + res;
	return res;
}