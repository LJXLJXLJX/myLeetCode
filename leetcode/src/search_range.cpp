#include "search_range.h"

using namespace std;

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
	vector<int> res;
	int len = nums.size();
	if (len == 0)
		return vector<int>{-1, -1};
	nums.push_back(nums.back() + 1);
	for (int i = 0; i < len; i++)
	{
		if ((target == nums[i] && i == 0) || (target == nums[i] && target != nums[i - 1]))
		{
			res.push_back(i);
		}
		if (target == nums[i] && target != nums[i + 1])
		{
			res.push_back(i);
			return res;
		}
	}
	return vector<int>{-1, -1};
}
