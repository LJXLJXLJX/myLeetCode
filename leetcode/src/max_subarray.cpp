#include "max_subarray.h"

using namespace std;

vector<int> findMaxCrossingSubarray(vector<int> &nums, int low, int mid, int high)
{
	int leftSum = INT_MIN;
	int sum = 0;
	int maxLeft = 0;
	int maxRight = 0;
	for (int i = mid; i >= low; --i)
	{
		sum += nums[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			maxLeft = i;
		}
	}
	int rightSum = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= high; ++i)
	{
		sum += nums[i];
		if (sum > rightSum)
		{
			rightSum = sum;
			maxRight = i;
		}
	}
	return vector<int>{maxLeft, maxRight, leftSum + rightSum};
}


vector<int> findMaxSubarray(vector<int> &nums, int low, int high)
{
	if (high == low)
		return vector<int> {low, high, nums[low]};

	int mid = (low + high) / 2;
	vector<int> temp;

	temp = findMaxSubarray(nums, low, mid);
	int leftLow = temp[0];
	int leftHigh = temp[1];
	int leftSum = temp[2];

	temp = findMaxSubarray(nums, mid + 1, high);
	int rightLow = temp[0];
	int rightHigh = temp[1];
	int rightSum = temp[2];

	temp = findMaxCrossingSubarray(nums, low, mid, high);
	int crossLow = temp[0];
	int crossHigh = temp[1];
	int crossSum = temp[2];

	if (leftSum >= rightSum && leftSum >= crossSum)
		return vector<int> {leftLow, leftHigh, leftSum };
	else if (rightSum >= leftSum && rightSum >= crossSum)
		return vector<int>{rightLow, rightHigh, rightSum};
	else
		return vector<int> {crossLow, crossHigh, crossSum};
}

int maxSubArray(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int low = 0;
	int high = nums.size() - 1;
	return findMaxSubarray(nums, low, high)[2];
}

//leetcode最快方法 非常巧妙
int _maxSubArray(vector<int>& nums) {
	int i;
	int sum = 0;
	if (nums.size() == 0)
		return 0;
	int maxsum = nums[0];
	for (i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (sum > maxsum)
			maxsum = sum;
		if (sum < 0)
			sum = 0;	//当一串的总和小于零 就可以舍弃掉它 并重新开始计数了
	}
	return maxsum;
}