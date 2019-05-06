#include "120_triangle.h"

using namespace std;

int minimumTotal(std::vector<std::vector<int>>& triangle)
{
	for (int i = triangle.size() - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle.front().front();
}
