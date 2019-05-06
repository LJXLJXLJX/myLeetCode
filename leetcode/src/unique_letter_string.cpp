#include "unique_letter_string.h"


using namespace std;


/*
	动态规划 复杂度O(n^2) 超时
*/


/*
In discussion
Instead of counting all unique characters and struggling with all possible substrings,
we can count for every char in S, how many ways to be found as a unique char.
We count and sum, and it will be out answer.
*/

int uniqueLetterString(std::string S)
{
	int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
	memset(index, -1, sizeof(int) * 52);
	for (int i = 0; i < N; ++i) {
		int c = S[i] - 'A';
		res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
		index[c][0] = index[c][1];
		index[c][1] = i;
	}
	for (int c = 0; c < 26; ++c)
		res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
	return res;
}
