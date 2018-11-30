#include "first_missing_positive.h"

int firstMissingPositive(std::vector<int>& nums)
{
	if (nums.size() == 0)
		return 1;
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] == i + 1 || nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) {
			i++;
		}
		else if (nums[i] != i + 1) {
			int tmp = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = tmp;
		}
	}
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] != i + 1) {
			return i + 1;
		}
	}
	return nums.size() + 1;
}
