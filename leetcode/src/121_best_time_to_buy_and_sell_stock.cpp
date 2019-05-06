#include "121_best_time_to_buy_and_sell_stock.h"

using namespace std;

// 最大子数组和
int maxSubSum(vector<int>&vec) {
	int f = vec[0];
	int max =f > 0 ? f : 0;
	for (int i = 1; i < vec.size(); ++i) {
		if (f < 0)
			f = vec[i];
		else
			f += vec[i];
		if (f > max)
			max = f;
	}
	return max;
}

int maxProfit(std::vector<int>& prices)
{
	if (prices.size() <= 1)
		return 0;
	
	for (int i = 0; i < prices.size() - 1; ++i) 
		prices[i] = prices[i + 1] - prices[i];
	prices.pop_back();

	return maxSubSum(prices);
}
