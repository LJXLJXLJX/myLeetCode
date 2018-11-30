#include "set_zeros.h"

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	set<int> rowNums, colNums;
	for (int i = 0; i < matrix.size(); ++i)
		for (int j = 0; j < matrix[0].size(); ++j)
			if (matrix[i][j] == 0)
			{
				rowNums.insert(i);
				colNums.insert(j);
			}
	for (int i = 0; i < matrix.size(); ++i)
		for (int j = 0; j < matrix[0].size(); ++j)
			if (rowNums.find(i) != rowNums.end() || colNums.find(j) != colNums.end())
				matrix[i][j] = 0;
}
