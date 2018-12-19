#include "decode_ways.h"


using namespace std;

//µİ¹é Ì«ÂıÁË
//void recur(string& s, int head, int& count, int recurDepth) {
//	cout << recurDepth << " " << head << endl;
//	if (head >= s.size())
//	{
//		if (head == s.size())
//			count++;
//		return;
//	}
//	if (s[head] == '0')
//		return;
//	if (s[head] > '2' || (s[head] == '2'&& s[head + 1] > '6'))
//		recur(s, head + 1, count, recurDepth + 1);
//	else if (s[head] == '1' || (s[head] == '2' && s[head + 1] <= '6'))
//	{
//		recur(s, head + 1, count, recurDepth + 1);
//		recur(s, head + 2, count, recurDepth + 1);
//	}
//	return;
//}
//
//int numDecodings(std::string s)
//{
//	int count = 0;
//	recur(s, 0, count, 0);
//	return count;
//}


// Concise cpp solution with O(1) space and O(n) time

int numDecodings(string s) {
	if (s.size() == 0 || s.front() == '0')
		return 0;
	if (s.size() == 1)
		return 1;
	//r1±íÊ¾dp[i-1]
	int r1 = 1, r2 = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '0'&& s[i - 1] != '1'&& s[i - 1] != '2')
			return 0;
		if (s[i] == '0') {
			int tmp = r2;
			r2 = r1;
			r1 = tmp;
			continue;
		}
		if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
			r2 += r1;
			r1 = r2 - r1;
		}
		else
			r1 = r2;
	}
	return r2;
}