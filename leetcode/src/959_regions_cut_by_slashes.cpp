#include "959_regions_cut_by_slashes.h"


using namespace std;




void draw(vector<vector<int>>&mat, int i, int j, int num) {
	if (i >= 0 && j >= 0 && i < mat.size() && j < mat.size() && mat[i][j] == 0) {
		mat[i][j] = 1;
		draw(mat, i - 1, j, num), draw(mat, i + 1, j, num), draw(mat, i, j - 1, num), draw(mat, i, j + 1, num);
	}
}

int regionsBySlashes(std::vector<std::string>& grid)
{
	int len = grid.size() * 3;
	vector<int> line(len, 0);
	vector<vector<int>>mat(len, line);
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid.size(); ++j) {
			if (grid[i][j] == '/') {
				mat[3 * i][3 * j + 2] = -1;
				mat[3 * i + 1][3 * j + 1] = -1;
				mat[3 * i + 2][3 * j] = -1;
			}
			else if (grid[i][j] == '\\') {
				mat[3 * i][3 * j] = -1;
				mat[3 * i + 1][3 * j + 1] = -1;
				mat[3 * i + 2][3 * j + 2] = -1;
			}
		}
	}

	int count = 0;

	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat.size(); ++j) {
			//´ýÍ¿É«
			if (mat[i][j] == 0) {
				count++;
				draw(mat, i, j, count);
			}
		}
	}

	return count;
}
