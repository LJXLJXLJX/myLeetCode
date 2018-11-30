#include "longest_palindrome.h"

using namespace std;

std::string longestPalindrome(std::string s)
{
	string sReverse("");
	int head = 0, tail = 0;
	int len = s.size();
	int maxLen = 0;
	string longestSubStr = "";
	for (int i = s.size() - 1; i >= 0; i--)
	{
		sReverse.push_back(s[i]);
	}
	for (int i = 0; i < len; i++)
	{
		if (len - i <= maxLen)
			break;
		head = i;
		for (int j = len - 1; j >= 0; j--)
		{
			if (j - i + 1 <= maxLen)
				break;
			if (s[i] == s[j])
			{
				tail = j;
				int reverseTail = len - 1 - head;
				int reverseHead = len - 1 - tail;
				string subStr(s, head, tail - head + 1);
				string subReverseStr(sReverse, reverseHead, reverseTail - reverseHead + 1);
				if (subStr == subReverseStr)
				{
					if (maxLen <= tail - head + 1)
					{
						maxLen = tail - head + 1;
						longestSubStr = subStr;
					}
				}
			}
		}
	}
	return longestSubStr;
}
