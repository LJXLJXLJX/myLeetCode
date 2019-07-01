#include "123_best_time_to_buy_and_sell_stock_3.h"

using namespace std;



int getMax(vector<int>&v, int head, int tail) {
	if (tail == head)
		return 0;
	vector<int> tmp(tail - head);
	int sum = 0;
	for (int i = head; i < tail; ++i) {
		if (sum >= 0)
			sum += v[i];
		else
			sum = v[i];
		tmp[i-head] = sum;
	}
	int ret = tmp[0];
	for (int i = 1; i < tmp.size(); ++i) {
		if (tmp[i] > ret)
			ret = tmp[i];
	}
	return ret;
}




int maxProfit3(std::vector<int>& prices)
{
	if (prices.size() <= 1)
		return 0;

	//将连续的上涨和下跌合并起来
	//问题简化为：在一段正负交替的数组中，找出一个子数组和最大（该子数组有一次机会将一个负数转换为正数）

	for (int i = 0; i < prices.size() - 1; ++i)
		prices[i] = prices[i + 1] - prices[i];
	prices.pop_back();
	//去除所有0
	int index = 0;
	for (int i = 0; i < prices.size(); ++i) {
		if (prices[i] != 0) {
			prices[index] = prices[i];
			++index;
		}
	}
	prices.resize(index);

	vector<int> rise_and_drop(prices.size());
	int sum = 0;
	index = 0;
	for (int i = 0; i < prices.size(); ++i) {
		if (prices[i] == 0)
			continue;
		sum += prices[i];
		if (i == prices.size() - 1) {
			rise_and_drop[index] = sum;
			index++;
			break;
		}
		if (prices[i + 1] * sum < 0) {
			rise_and_drop[index] = sum;
			index++;
			sum = 0;
		}
	}
	rise_and_drop.resize(index);
	if (rise_and_drop.empty())
		return 0;
	if (rise_and_drop.size() == 1)
		return rise_and_drop[0] > 0 ? rise_and_drop[0] : 0;

	index = rise_and_drop[0] < 0 ? 0 : 1;
	int max = rise_and_drop[0];
	for (index; index < rise_and_drop.size(); index += 2) {
		int left = getMax(rise_and_drop, 0, index);
		int right = getMax(rise_and_drop, index + 1, rise_and_drop.size());
		if (left + right > max)
			max = left + right;
	}
	return max;
}
