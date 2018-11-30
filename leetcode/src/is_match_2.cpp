#include "is_match_2.h"

using namespace std;

bool isMatch2(std::string s, std::string p)
{
	int m = s.size();
	int n = p.size();
	vector<vector<bool>> matchTable(m + 1, vector<bool>(n + 1, false));
	matchTable[0][0] = true;
	for (int j = 1; j <= n; ++j)
		matchTable[0][j] = p[j - 1] == '*' && matchTable[0][j - 1] == true;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (p[j - 1] != '*')
				matchTable[i][j] = matchTable[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
			else
				matchTable[i][j] = matchTable[i - 1][j] || matchTable[i][j - 1];
	return matchTable[m][n];
}
