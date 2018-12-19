#include "interleaving_string.h"

using namespace std;

//递归解法 管用 但是太慢了
/*
void isInterleaveRecur(std::string& s1, std::string& s2, std::string&s3, int index1, int index2, bool& out) {
	if (out == true)
		return;
	if (index1 == s1.size() - 1 && index2 == s2.size() - 1) {
		out = true;
		return;
	}
	if (s1[index1] != s3[index1 + index2] && s2[index2] != s3[index1 + index2])
		return;
	if (s1[index1] == s3[index1 + index2] && s2[index2] == s3[index1 + index2]) {
		isInterleaveRecur(s1, s2, s3, index1 + 1, index2, out);
		isInterleaveRecur(s1, s2, s3, index1, index2 + 1, out);
	}
	else if (s1[index1] == s3[index1 + index2])
		isInterleaveRecur(s1, s2, s3, index1 + 1, index2, out);
	else
		isInterleaveRecur(s1, s2, s3, index1, index2 + 1, out);
}

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
	if (s1.size() + s2.size() != s3.size())
		return false;
	//插入哨兵
	s1.push_back('#');
	s2.push_back('#');
	bool ret = false;
	isInterleaveRecur(s1, s2, s3, 0, 0, ret);
	return ret;
}
*/


//动态规划
bool isInterleave(std::string s1, std::string s2, std::string s3)
{
	if (s1.size() + s2.size() != s3.size())
		return false;
	vector<vector<int>> dp(s2.size() + 1, vector<int>(s1.size() + 1, 0));
	dp[0][0] = 1;

	//初始化第一行
	for (int j = 1; j < dp[0].size(); ++j) {
		if (dp[0][j - 1] == 0)
			dp[0][j] = 0;
		else if (s1[j - 1] == s3[j - 1])
			dp[0][j] = 1;
	}
	//初始化第一列
	for (int i = 1; i < dp.size(); ++i) {
		if (dp[i - 1][0] == 0)
			dp[i][0] = 0;
		else if (s2[i - 1] == s3[i - 1])
			dp[i][0] = 1;
	}
	for (int i = 1; i < dp.size(); ++i)
		for (int j = 1; j < dp[0].size(); ++j) {
			int b1 = dp[i][j - 1] && s1[j - 1] == s3[i + j - 1];
			int b2 = dp[i - 1][j] && s2[i - 1] == s3[i + j - 1];
			dp[i][j] = b1 || b2;
		}

	//*******调试用************
	//for (auto row : dp) {
	//	for (int ele : row)
	//		cout << ele << " ";
	//	cout << endl;
	//}
	//*************************

	return dp.back().back();
}
