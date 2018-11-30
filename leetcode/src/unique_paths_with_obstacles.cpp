#include "unique_paths_with_obstacles.h"

using namespace std;

//�ö�̬�滮�ǳ���
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
		return 0;
	dp[1][1] = 1;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if ((i == 1 && j == 1) || obstacleGrid[i - 1][j - 1] == 1)
				continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m][n];
}
