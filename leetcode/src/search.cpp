#include "search.h"

int search(std::vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	if (target >= nums[0])
		for (int i = 0; i < nums.size(); i++)
		{
			if (target == nums[i])
				return i;
		}
	else
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (target == nums[i])
				return i;
		}
	return -1;
}
