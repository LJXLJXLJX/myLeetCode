#include "jump.h"

int jump(std::vector<int>& nums)
{
	if (nums.size() <= 1)
		return 0;
	int index = 0;
	int jumpTimes = 0;
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
		index = maxStepIndex;
		++jumpTimes;
	}
	return ++jumpTimes;
}
