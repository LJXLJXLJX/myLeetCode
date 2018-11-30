#include "rotate.h"

using namespace std;

void rotate(std::vector<std::vector<int>>& matrix)
{
	int n = matrix.size();

	for (int i = 0; i < n; ++i)
		for (int j = n - 1 - i; j >= 0; --j)
			if (i + j != n - 1)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
	for (int i = 0; i < n / 2; ++i)
		swap(matrix[i], matrix[n - 1 - i]);
}
