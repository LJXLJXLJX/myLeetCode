#include "200_number_of_islands.h"

using namespace std;


void helper(std::vector<std::vector<char>>& grid, int i, int j, char num) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	grid[i][j] = num;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (i - 1 >= 0 && grid[i - 1][j] == '1') {
			q.push({ i - 1,j });
			grid[i - 1][j] = num;
		}
		if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
			q.push({ i + 1,j });
			grid[i + 1][j] = num;
		}
		if (j - 1 >= 0 && grid[i][j - 1] == '1') {
			q.push({ i,j - 1 });
			grid[i][j - 1] = num;
		}
		if (j + 1 < grid[0].size() && grid[i][j + 1] == '1'){
			q.push({ i,j + 1 });
			grid[i][j + 1] = num;
		}
	}
}


int numIslands(std::vector<std::vector<char>>& grid)
{
	if (grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	int ret = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '1') {
				ret++;
				helper(grid, i, j, 'a' + ret);
			}
		}
	}
	return ret;
}
