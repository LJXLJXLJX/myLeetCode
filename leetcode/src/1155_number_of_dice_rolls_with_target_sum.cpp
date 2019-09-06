#include "1155_number_of_dice_rolls_with_target_sum.h"


using namespace std;

typedef long long ll;


int numRollsToTarget(int d, int f, int target)
{
	const int mod = 1000000007;
	vector<vector<int>> dp(d + 1, vector<int>(target + 1));
	for (int j = 1; j <= min(f, target); ++j)
		dp[1][j] = 1;
	for (int i = 1; i <= min(d, target); ++i)
		dp[i][i] = 1;

	for (int i = 2; i <= d; ++i) {
		for (int j = i + 1; j <= target; ++j) {
			for (int k = 1; k <= f; k++) {
				if (j - k >= 1) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
				}
			}
		}
	}
	return dp.back().back();
}
