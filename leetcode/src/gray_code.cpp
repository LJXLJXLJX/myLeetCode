#include "gray_code.h"
#include <bitset>

/*
leetcode ��һ�ַǳ����ŵ�ʵ��
*/

using namespace std;

void utils(bitset<32>& bits, vector<int>& result, int k) {
	if (k == 0) {
		result.push_back(bits.to_ulong());
	}
	else {
		utils(bits, result, k - 1);
		bits.flip(k - 1);
		utils(bits, result, k - 1);
	}
}

std::vector<int> grayCode(int n)
{
	bitset<32> bits;
	vector<int> result;
	utils(bits, result, n);
	return result;
}
