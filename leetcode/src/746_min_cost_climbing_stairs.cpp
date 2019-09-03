#include "746_min_cost_climbing_stairs.h"


using namespace std;


int minCostClimbingStairs(std::vector<int>& cost)
{
	cost.push_back(0);
	vector<int> dp(cost.size());
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < dp.size(); ++i) {
		dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
	}
	return dp.back();
}
