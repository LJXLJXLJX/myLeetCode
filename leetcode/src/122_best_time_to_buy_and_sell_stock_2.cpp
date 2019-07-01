#include "122_best_time_to_buy_and_sell_stock_2.h"

using namespace std;

int maxProfit2(std::vector<int>& prices)
{
	int profit = 0;
	for (int i = 0; i < prices.size() - 1; ++i) {
		int diff = prices[i + 1] - prices[i];
		if (diff > 0)
			profit += diff;
	}
	return profit;
}
