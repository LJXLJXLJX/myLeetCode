#include "subsets.h"

using namespace std;

void subsetRecurse(vector<vector<int>>&res, vector<int>&subset, int currentIndex, vector<int> &nums) {
	res.push_back(subset);
	for (int i = currentIndex; i < nums.size(); ++i)
	{
		subset.push_back(nums[i]);
		subsetRecurse(res, subset, i + 1, nums);
	}
	if (!subset.empty())
		subset.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> subset;
	subsetRecurse(res, subset, 0, nums);
	return res;
}
