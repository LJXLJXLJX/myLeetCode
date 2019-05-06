#pragma once
#include "heads.h"




//“合并”相邻且比当前小的


class StockSpanner {
public:
	StockSpanner() = default;

	int next(int price);

private:
	std::stack<std::pair<int, int>> s;
};