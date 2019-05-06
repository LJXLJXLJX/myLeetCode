#include "118_pascals_triangle.h"

using namespace std;

std::vector<std::vector<int>> generate_pascal(int numRows)
{
	if (numRows == 0)
		return {};
	vector<vector<int>> ret(numRows, vector<int>{});
	ret[0] = { 1 };
	for (int i = 1; i < numRows; ++i) {
		ret[i].assign(i + 1, 0);
		ret[i].front() = 1;
		ret[i].back() = 1;
		int index = 0;
		for (int j = 0; j < i - 1; ++j)
			ret[i][++index] = ret[i - 1][j] + ret[i - 1][j + 1];
	}
	return ret;
}
