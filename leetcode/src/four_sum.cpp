#include "four_sum.h"

using namespace std;

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
	vector<vector<int>> res;
	int len = nums.size();
	if (len < 4)
		return res;
	sort(nums.begin(), nums.end());
	int first = 0, second = 1, head = 2, tail = len - 1;
	for (first; first <= len - 4; first++)
	{
		for (second = first + 1; second <= len - 3; second++)
		{
			head = second + 1;
			tail = len - 1;
			if (nums[first] + nums[second] > target && nums[head] >= 0)
				break;
			if (nums[first] + nums[second] < target && nums[tail] <= 0)
				break;
			while (head < tail)
			{
				if (nums[first] + nums[second] + nums[head] + nums[tail] == target)
				{
					res.push_back(vector<int>{nums[first], nums[second], nums[head], nums[tail]});
					while (nums[head] == nums[head + 1])
					{
						head++;
						if (head >= tail)
							break;
					}
					head++;
					while (nums[tail - 1] == nums[tail] && head < tail)
					{
						tail--;
						if (head >= tail)
							break;
					}
					tail--;
				}
				else if (nums[first] + nums[second] + nums[head] + nums[tail] < target)
				{
					while (nums[head] == nums[head + 1])
					{
						head++;
						if (head >= tail)
							break;
					}
					head++;
				}
				else
				{
					while (nums[tail - 1] == nums[tail] && head < tail)
					{
						tail--;
						if (head >= tail)
							break;
					}
					tail--;
				}
			}
			while (nums[second + 1] == nums[second] && second < len - 3)
				second++;
		}
		while (nums[first + 1] == nums[first] && first < len - 3)
			first++;
	}
	return res;
}
