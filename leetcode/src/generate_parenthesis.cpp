#include "generate_parenthesis.h"


using namespace std;

void parenthesisGenerator(int left, int right, std::vector<std::string>& res, std::string str)
{
	if (left == 0 && right == 0)
	{
		res.push_back(str);
		return;
	}
	if (left > 0)
		parenthesisGenerator(left - 1, right, res, str + "(");
	if (left < right)
		parenthesisGenerator(left, right - 1, res, str + ")");
}

std::vector<std::string> generateParenthesis(int n)
{
	vector<string> res;
	parenthesisGenerator(n, n, res, "");
	return res;
}
