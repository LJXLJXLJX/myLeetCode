#pragma once
#include "heads.h"




//���ϲ��������ұȵ�ǰС��


class StockSpanner {
public:
	StockSpanner() = default;

	int next(int price);

private:
	std::stack<std::pair<int, int>> s;
};