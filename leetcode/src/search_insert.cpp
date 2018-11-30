#include "search_insert.h"

int searchInsert(std::vector<int>& nums, int target)
{
	int len = nums.size();
	if (len == 0 || target < nums[0])
		return 0;
	for (int i = 0; i < len; i++)
	{
		if (target == nums[i])
			return i;
		if (target > nums[i] && (target < nums[i + 1] || i == len - 1))
			return i + 1;
	}
	return len;
}
