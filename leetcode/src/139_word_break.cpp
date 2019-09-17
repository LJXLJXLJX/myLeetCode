#include "139_word_break.h"


using namespace std;

bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{

	unordered_set<string> wordSet(wordDict.begin(),wordDict.end());

	vector<int> dp(s.size() + 1);
	dp[0] = 1;
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (dp[j] == 1) {
				string tmp = s.substr(j, i - j);
				if (wordSet.find(tmp) != wordSet.end()) {
					dp[i] = true;
					break;
				}
			}
		}
	}
	return dp.back();
}
