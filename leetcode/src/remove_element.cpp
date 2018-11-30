#include "remove_element.h"

using namespace std;

int removeElement(std::vector<int>& nums, int val)
{
	int len = nums.size();
	int index = 0, valIndex = 0;
	while (valIndex < len)
	{
		if (nums[valIndex] == val)
		{
			valIndex++;
			continue;
		}
		else
		{
			nums[index] = nums[valIndex];
			index++;
			valIndex++;
		}
	}
	return index;
}

