#include "search_matrix.h"

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty()
		|| matrix[0].empty()
		|| target<matrix.front().front()
		|| target>matrix.back().back())
		return false;
	for (auto row : matrix)
	{
		if (target >= row.front() && target <= row.back())
		{
			if (find(row.begin(), row.end(), target) != row.end())
				return true;
			else
				return false;
		}
	}
	return false;
}
