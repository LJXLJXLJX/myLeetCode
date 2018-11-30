#include "permute.h"

using namespace std;

void permuteDFS(std::vector<int> nums, std::vector<int> permutation, std::vector<std::vector<int>>& res)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		vector<int> temp = nums;
		permutation.push_back(temp[i]);
		temp.erase(temp.begin() + i);
		if (temp.size() == 0)
		{
			res.push_back(permutation);
			return;
		}
		permuteDFS(temp, permutation, res);
		permutation.pop_back();
	}
}

std::vector<std::vector<int>> permute(std::vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> permutation;
	permuteDFS(nums, permutation, res);
	return res;
}
