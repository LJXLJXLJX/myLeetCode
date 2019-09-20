#include "152_maximum_product_subarray.h"


using namespace std;


//动态规划 同时维持两个dp数组（可优化成常数），一个存最小负数，一个存最大正数


int maxProduct(std::vector<int>& nums)
{
	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return nums[0];
	int neg = 0;
	int pos = 0;
	int ret = nums[0];
	for (auto num : nums) {
		int last_pos = pos;
		int last_neg = neg;
		if (num == 0) {
			neg = 0;
			pos = 0;
		}
		else if (num < 0) {
			pos = last_neg * num;
			neg = min(num, num*last_pos);
		}
		else {
			neg = last_neg * num;
			pos = max(num, num*last_pos);
		}

		ret = max(pos, ret);
	}

	return ret;
}
