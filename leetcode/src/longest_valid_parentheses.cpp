#include "longest_valid_parentheses.h"

using namespace std;

int longestValidParentheses(std::string s)
{
	if (s.size() <= 1)
		return 0;
	int sLen = s.size();
	int maxLen = 0;
	stack<int> stk;
	stk.push(-1);
	for (int i = 0; i < sLen; i++)
	{
		if (s[i] == '(')
			stk.push(i);
		else if (s[i] == ')')
		{
			stk.pop();
			if (stk.empty())
				stk.push(i);
			if (i - stk.top() > maxLen)
				maxLen = i - stk.top();
		}
	}
	return maxLen;
}
