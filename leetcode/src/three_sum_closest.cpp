#include "three_sum_closest.h"

int threeSumClosest(std::vector<int>& nums, int target)
{
	const int len = nums.size();
	int head = 1, tail = len - 1;
	int distance = 0;
	sort(nums.begin(), nums.end());
	int res = nums[0] + nums[1] + nums[len - 1];
	int minDistance = abs(res - target);

	for (int i = 0; i <= len - 3; i++)
	{
		head = i + 1;
		tail = len - 1;
		while (head < tail)
		{
			distance = nums[i] + nums[head] + nums[tail] - target;
			if (distance == 0)
				return target;
			if (abs(distance) < minDistance)
			{
				minDistance = abs(distance);
				res = nums[i] + nums[head] + nums[tail];
			}
			if (distance < 0)
				head++;
			else
				tail--;
		}
		while (nums[i + 1] == nums[i])
		{
			i++;
			if (i >= len - 1)
				break;
		}
	}
	return res;
}
