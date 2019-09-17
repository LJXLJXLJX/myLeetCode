#include "136_single_number.h"



// 低效解法 排序
//int singleNumber(std::vector<int>& nums)
//{
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < nums.size(); i += 2) {
//		if (i == nums.size() - 1 ||nums[i] != nums[i + 1])
//			return nums[i];
//	}
//	return 0;
//}



//高效解法 异或
int singleNumber(std::vector<int>& nums) {
	//xor all numbers, the left over number would be the non repeated one
	// since the equl numbers cancel out each others bits
	int num = 0;
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		num ^= nums[i];
	}
	return num;
}