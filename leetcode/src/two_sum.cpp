#include "two_sum.h"

using namespace std;

std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target)
{
	vector<int> group;	//the group consist of two numbers whose sum is target
	vector<vector<int>> res;
	//if has been sorted in threeNum , annotation the follow row
	//sort(nums.begin(), nums.end());
	int len = nums.size();
	int head = 0;
	int tail = len - 1;
	if (len < 2)
		return res;
	while (head < tail)
	{
		if (nums[head] + nums[tail] == target)
		{
			group = { nums[head],nums[tail] };
			res.push_back(group);
			while (nums[head + 1] == nums[head])
			{
				head++;
				if (head > tail)
					break;
			}
			head++;
			while (nums[tail - 1] == nums[tail])
			{
				tail--;
				if (tail < head)
					break;
			}
			tail--;
		}
		else if (nums[head] + nums[tail] < target)
		{
			head++;
		}
		else
		{
			tail--;
		}
	}
	return res;
}
