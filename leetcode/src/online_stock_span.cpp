#include "online_stock_span.h"


using namespace std;



int StockSpanner::next(int price)
{
	int res = 1;
	while (!s.empty() && price >= s.top().first) {
		res += s.top().second;
		s.pop();
	}
	s.push({ price,res });
	return res;
}
