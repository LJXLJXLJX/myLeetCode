#include "combine.h"

using namespace std;

void combineRecurse(vector<vector<int>>&res, vector<int> &combination, int currentLen, int n, int k) {
	if (currentLen == k)
	{
		res.push_back(combination);
		combination.pop_back();
		return;
	}
	for (int i = combination.empty() ? 1 : combination.back() + 1; i <= n; ++i)
	{
		if (combination.empty() && i > n - k + 1)
			return;
		combination.push_back(i);
		combineRecurse(res, combination, currentLen + 1, n, k);

	}
	if (!combination.empty())
		combination.pop_back();
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	if (k > n)
		return res;
	vector<int> combination;
	combineRecurse(res, combination, 0, n, k);
	return res;
}
