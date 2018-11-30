#include "maximalRectangle.h"




using namespace std;

/*
假设matrix有n行 可以把每前i行看成一个直方图 然后找到最大的直方图中的矩形了
*/

int maximalRectangle(std::vector<std::vector<char>>& matrix)
{
	int row = matrix.size();
	if (row == 0)
		return 0;
	int col = matrix[0].size();
	if (col == 0)
		return 0;
	vector<vector<int>> height(row + 1, vector<int>(col));
	vector<vector<int>> left(row + 1, vector<int>(col));
	vector<vector<int>> right(row + 1, vector<int>(col));
	for (int j = 0; j < col; ++j)
		right[0][j] = col;
	int maxArea = 0;
	for (int i = 1; i < row + 1; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int curLeft = 0, curRight = 0;
			if (matrix[i - 1][j] == '0')
			{
				height[i][j] = 0;
				left[i][j] = 0;
				right[i][j] = col;
			}
			else
			{
				height[i][j] = height[i - 1][j] + 1;
				curLeft = j, curRight = j + 1;
				while (curLeft > 0 && matrix[i - 1][curLeft-1] == '1')
					curLeft--;
				while (curRight < col && matrix[i - 1][curRight] == '1')
					curRight++;
				left[i][j] = max(curLeft, left[i - 1][j]);
				right[i][j] = min(curRight, right[i - 1][j]);
			}
			
			int area = height[i][j] * (right[i][j] - left[i][j]);
			maxArea = max(maxArea, area);
		}
	}

	//*******调试用**************
	cout << "height" << endl;
	for (auto r : height)
	{
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}

	cout << "left" << endl;
	for (auto r : left)
	{
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}

	cout << "right" << endl;
	for (auto r : right)
	{
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}

	//***************************


	return maxArea;
}
