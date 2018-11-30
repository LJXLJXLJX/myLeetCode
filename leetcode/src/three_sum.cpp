#include "three_sum.h"

using namespace std;

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
	vector<vector<int>> res;
	int len = nums.size();
	if (len < 3)
		return res;
	int index = 0;
	sort(nums.begin(), nums.end());
	while (index <= len - 3)
	{
		if (nums[index] > 0)
			break;
		vector<int> subNums(nums.begin() + index + 1, nums.end());
		for (auto group : twoSum(subNums, -nums[index]))
		{
			group.push_back(nums[index]);
			res.push_back(group);
		}
		while (nums[index + 1] == nums[index])
		{
			index++;
			if (index > len - 3)
				return res;
		}
		index++;
	}
	return res;
}
