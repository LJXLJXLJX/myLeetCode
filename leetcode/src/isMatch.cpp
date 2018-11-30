#include "isMatch.h"

using namespace std;

bool isMatch(std::string s, std::string p)
{
	int m = s.size();
	int n = p.size();
	vector<vector<bool>> matchTable(m + 1, vector<bool>(n + 1, false));
	matchTable[0][0] = true;
	//the case when i=0,j>0  can't match obviously ,keep matchTable[0][j>0] be false.

	//the case when j=0:
	//will match if string p's length>1 and the last letter of p
	//must be '*' and the letter in front of it for two letters 
	//also should be '*' if exist
	for (int j = 1; j <= n; j++)
	{
		matchTable[0][j] = j > 1 && p[j - 1] == '*' && matchTable[0][j - 2];
	}
	//the case when m>0,n>0
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//the case without '*'
			if (p[j - 1] != '*')
				//if match , the substrs without last letters must match , 
				//and the last letters should be equal or the last letter
				//of p is '.'
				matchTable[i][j] = matchTable[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
			else
				//two cases, * matchs empty or not empty (suppose it x).
				//case 1:matchTable[i][j]==matchTable[i][j] (eliminate p's x*)
				//case 2:matchTable[i-1][j]==matchTable[i][j] and the last letter of s should be x or x is '.'
				matchTable[i][j] = matchTable[i][j - 2] || matchTable[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
		}
	}
	return matchTable[m][n];
}
