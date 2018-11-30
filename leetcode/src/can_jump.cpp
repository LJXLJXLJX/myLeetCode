#include "can_jump.h"

using namespace std;

bool canJump(vector<int>& nums) {
	if (nums.size() <= 1)
		return true;
	int index = 0;
	while (index + nums[index] < nums.size() - 1)
	{
		int maxStep = 0;
		int maxStepIndex = 0;
		int count = 0;
		for (int i = index + 1; i <= index + nums[index]; ++i, ++count)
		{
			if (count + nums[i] > maxStep)
			{
				maxStep = nums[i] + count;
				maxStepIndex = i;
			}
		}
		if (maxStep == 0)
			return false;
		index = maxStepIndex;
	}
	return true;
}