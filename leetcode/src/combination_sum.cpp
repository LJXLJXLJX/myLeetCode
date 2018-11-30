#include "combination_sum.h"

using namespace std;

void recurseCombinationSum(std::vector<std::vector<int>>& res, std::vector<int>& candidates, std::vector<int> combination, int target, int begin)
{
	if (target == 0)
	{
		res.push_back(combination);
		return;
	}
	for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i)
	{
		combination.push_back(candidates[i]);
		recurseCombinationSum(res, candidates, combination, target - candidates[i], i);
		combination.pop_back();
	}
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> combination;
	recurseCombinationSum(res, candidates, combination, target, 0);
	return res;
}
