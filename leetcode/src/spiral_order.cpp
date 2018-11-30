#include "spiral_order.h"

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int topBound = 0;
	int leftBound = 0;
	int bottomBound = matrix.size() - 1;
	int rightBound = matrix[0].size() - 1;
	int x = 0;
	int y = 0;
	while (1)
	{
		for (int i = leftBound; i <= rightBound; ++i)
		{
			res.push_back(matrix[x][y]);
			if (i != rightBound)
				++y;
		}
		++topBound;
		++x;
		if (res.size() == matrix.size()*matrix[0].size())
			break;
		for (int i = topBound; i <= bottomBound; ++i)
		{
			res.push_back(matrix[x][y]);
			if (i != bottomBound)
				++x;
		}
		--rightBound;
		--y;
		if (res.size() == matrix.size()*matrix[0].size())
			break;
		for (int i = rightBound; i >= leftBound; --i)
		{
			res.push_back(matrix[x][y]);
			if (i != leftBound)
				--y;
		}
		--bottomBound;
		--x;
		if (res.size() == matrix.size()*matrix[0].size())
			break;
		for (int i = bottomBound; i >= topBound; --i)
		{
			res.push_back(matrix[x][y]);
			if (i != topBound)
				--x;
		}
		++leftBound;
		++y;
		if (res.size() == matrix.size()*matrix[0].size())
			break;
	}
	return res;
}
