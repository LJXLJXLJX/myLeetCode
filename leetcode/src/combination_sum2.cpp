#include "combination_sum2.h"

using namespace std;

void combinationSum2Recurse(std::vector<int>::iterator n, std::vector<int>& current, std::vector<std::vector<int>>& res, const std::vector<int>& candidates, int target)
{
	if (target == 0)
	{
		res.push_back(current);
		return;
	}

	for (; n != candidates.end() && *n <= target; ++n)
	{
		current.push_back(*n);
		combinationSum2Recurse(n + 1, current, res, candidates, target - *n);
		current.pop_back();
		while (n + 1 != candidates.end() && *(n + 1) == *n) ++n;
	}
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	vector<int> current;
	sort(candidates.begin(), candidates.end());
	combinationSum2Recurse(candidates.begin(), current, res, candidates, target);
	return res;
}
