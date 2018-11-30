#include "generate_matrix.h"

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n, -1));
	if (matrix.size() == 0)
		return matrix;
	int topBound = 0;
	int leftBound = 0;
	int bottomBound = matrix.size() - 1;
	int rightBound = matrix[0].size() - 1;
	int x = 0;
	int y = 0;
	int count = 0;
	while (1)
	{
		for (int i = leftBound; i <= rightBound; ++i)
		{
			matrix[x][y] = ++count;
			if (i != rightBound)
				++y;
		}
		++topBound;
		++x;
		if (count == n * n)
			break;
		for (int i = topBound; i <= bottomBound; ++i)
		{
			matrix[x][y] = ++count;
			if (i != bottomBound)
				++x;
		}
		--rightBound;
		--y;
		if (count == n * n)
			break;
		for (int i = rightBound; i >= leftBound; --i)
		{
			matrix[x][y] = ++count;
			if (i != leftBound)
				--y;
		}
		--bottomBound;
		--x;
		if (count == n * n)
			break;
		for (int i = bottomBound; i >= topBound; --i)
		{
			matrix[x][y] = ++count;
			if (i != topBound)
				--x;
		}
		++leftBound;
		++y;
		if (count == n * n)
			break;
	}
	return matrix;
}