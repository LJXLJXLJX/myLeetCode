#include "115_distinct_subsequences.h"

using namespace std;


// 超时
//void dfs(string& s, string& t, int si, int ti, string cur, int& ret) {
//	if (cur.size() == t.size()) {
//		ret++;
//		return;
//	}
//
//	if (s.size() - si + cur.size() < t.size() - ti)
//		return;
//
//	for (int i = si; i < s.size(); ++i) {
//		if (s[i] == t[ti]) {
//			dfs(s, t, i + 1, ti + 1, cur + s[i], ret);
//		}
//	}
//}
//
//int numDistinct(std::string s, std::string t)
//{
//	int si = 0, ti = 0, ret = 0;
//	string cur;
//	dfs(s, t, si, ti, cur, ret);
//	return ret;
//}



//应该使用动态规划

int numDistinct(std::string s, std::string t)
{
	int m = t.length(), n = s.length();
	vector<int> cur(m + 1, 0);
	cur[0] = 1;
	for (int j = 1; j <= n; j++) {
		int pre = 1;
		for (int i = 1; i <= m; i++) {
			int temp = cur[i];
			cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
			pre = temp;
		}
	}
	return cur[m];
}