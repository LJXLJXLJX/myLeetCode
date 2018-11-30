#include "permute_unique.h"

using namespace std;

void permuteUniqueDFS(std::vector<int> nums, std::vector<int> permutation, std::vector<std::vector<int>>& res)
{
	vector<int> alreadyUsed;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (find(alreadyUsed.begin(), alreadyUsed.end(), nums[i]) != alreadyUsed.end())
			continue;
		vector<int> temp = nums;
		alreadyUsed.push_back(temp[i]);
		permutation.push_back(temp[i]);
		temp.erase(temp.begin() + i);
		if (temp.size() == 0)
		{
			res.push_back(permutation);
			return;
		}
		permuteUniqueDFS(temp, permutation, res);
		permutation.pop_back();
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> permutation;
	permuteUniqueDFS(nums, permutation, res);
	return res;
}
