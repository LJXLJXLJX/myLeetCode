#include "min_distance.h"

using namespace std;

int minDistance(string word1, string word2) {
	word1 = "#" + word1;
	word2 = "#" + word2;
	vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
	for (int i = 0; i < word1.size(); ++i)
		dp[i][0] = i;
	for (int j = 1; j < word2.size(); ++j)
		dp[0][j] = j;
	for (int i = 1; i < word1.size(); ++i)
	{
		for (int j = 1; j < word2.size(); ++j)
		{
			int temp1 = dp[i - 1][j] + 1;
			int temp2 = dp[i][j - 1] + 1;
			int temp3 = dp[i - 1][j - 1];
			if (word1[i] != word2[j])
				temp3 += 1;
			dp[i][j] = min(temp1, min(temp2, temp3));
		}
	}
	return dp.back().back();
}
