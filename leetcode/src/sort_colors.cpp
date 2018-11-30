#include "sort_colors.h"

using namespace std;

void sortColors(vector<int>& nums) {
	int count = 0;
	for (int i = 0; i < nums.size();)
	{
		if (count == nums.size())
			break;
		if (nums[i] == 0 && i > 0 && nums[i - 1] == 1)
		{
			nums.erase(nums.begin() + i);
			nums.insert(nums.begin(), 0);
		}
		else if (nums[i] == 2 && i < nums.size() - 1)
		{
			nums.erase(nums.begin() + i);
			nums.push_back(2);
			++count;
		}
		else
		{
			++i;
			++count;
		}
	}
}
