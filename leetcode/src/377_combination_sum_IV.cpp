#include "377_combination_sum_IV.h"


using namespace std;



void helper(vector<size_t>&dp,vector<int>&nums, int target) {
	for (int diff : nums) {
		if (diff < 0)
			continue;
		else if (diff == target)
			dp.back()++;
		else {
			dp.back() += dp[dp.size() -1- diff];
		}
	}
	for (int i = 0; i < dp.size() - 1; ++i)
		dp[i] = dp[i + 1];
	dp.back() = 0;

	//for (auto i : dp)
	//	cout << i << " ";
	//cout << endl;

}


int combinationSum4(std::vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1) {
		if (target%nums[0] == 0)
			return 1;
		else
			return 0;
	}
	sort(nums.begin(), nums.end());

	if (nums.front() > target)
		return 0;

	vector<size_t> dp(nums.back()+ 1);
	dp[dp.size() - 2] = 1;
	int cur = nums[0];
	while (cur < target) {
		cur++;
		helper(dp, nums, cur);
	}
	return dp[dp.size()-2];
}



//超时 应该用dp
//void dfs(vector<int>& nums, int target, int& ret) {
//	if (target < 0) {
//		return;
//	}
//
//	if (target == 0) {
//		ret++;
//		return;
//	}
//
//	for (auto num : nums) {
//		dfs(nums, target - num, ret);
//	}
//}
//
//
//int combinationSum4(std::vector<int>& nums, int target)
//{
//	int ret = 0;
//	dfs(nums, target, ret);
//	return ret;
//}


