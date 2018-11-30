#include "next_permutation.h"

using namespace std;

void nextPermutation(std::vector<int>& nums)
{
	int len = nums.size();
	if (len <= 1)
		return;
	int dropPointFromTailToHead = -1;	//从尾向头的下降点
	for (int i = len - 1; i > 0; i--)
	{
		if (nums[i - 1] < nums[i])
		{
			dropPointFromTailToHead = i - 1;
			break;
		}
	}
	if (dropPointFromTailToHead < 0)
	{
		sort(nums.begin(), nums.end());
		return;
	}
	for (int i = len - 1; i > dropPointFromTailToHead; i--)
	{
		if (nums[i] > nums[dropPointFromTailToHead])
		{
			swap(nums[i], nums[dropPointFromTailToHead]);
			break;
		}
	}
	sort(nums.begin() + dropPointFromTailToHead + 1, nums.end());
}
