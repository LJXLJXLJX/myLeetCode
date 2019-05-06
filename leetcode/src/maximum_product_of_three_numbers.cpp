#include "maximum_product_of_three_numbers.h"


using namespace std;

int maximumProduct(std::vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int max1 = nums[0] * nums[1];
	if (max1 < 0) {
		max1 *= nums[2];
	}
	else {
		if (nums.back() >= 0)
			max1 *= nums.back();
		else
			max1 *= nums[2];
	}
	int len = nums.size();
	int max2 = nums[len - 1] * nums[len - 2];
	if (max2 < 0) {
		max2 *= nums[0];
	}
	else {
		max2 *= nums[len - 3];
	}
	return max(max1, max2);
}
