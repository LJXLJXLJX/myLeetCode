#include "is_valid.h"

using namespace std;

bool isValid(std::string s)
{
	if (s.size() % 2 == 1)
		return false;
	stack<char> stk;
	for (char c : s)
	{
		switch (c)
		{
		case '{':
		case '[':
		case '(':
			stk.push(c);
			break;
		case '}':
			if (stk.empty())
				return false;
			else if (stk.top() != '{')
				return false;
			else
				stk.pop();
			break;
		case ']':
			if (stk.empty())
				return false;
			else if (stk.top() != '[')
				return false;
			else
				stk.pop();
			break;
		case ')':
			if (stk.empty())
				return false;
			else if (stk.top() != '(')
				return false;
			else
				stk.pop();
			break;
		default:
			return false;
		}
	}
	return stk.empty();
}
