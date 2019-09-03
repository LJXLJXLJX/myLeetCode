#include "198._house_robber.h"

using namespace std;




int rob(std::vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 0)
		return max(nums[0],nums[1]);

	vector<int> dp(nums.size());
	dp[0] = nums[0];
	dp[1] = nums[1];
	for (int i = 2; i < dp.size(); ++i) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}


	return dp.back();
}
