#include "mutiply.h"

using namespace std;

std::string strMulChar(std::string num, char digit)
{
	if (digit == '0')
		return "0";
	string res;
	int carry = 0;
	int num1 = 0;
	int num2 = 0;
	for (int i = num.size() - 1; i >= 0; --i)
	{
		num1 = num[i] - '0';
		num2 = digit - '0';
		int temp = num1 * num2 + carry;
		res.push_back(temp % 10 + '0');
		carry = temp / 10;
	}
	if (carry != 0)
		res.push_back(carry + '0');	//别忘记加上最后的进位
	return res;		//返回的res是反向的 
}

std::string multiply(std::string num1, std::string num2)
{
	if (num1 == "0" || num2 == "0")
		return "0";
	string res;
	vector<string> resLines;
	int maxLen = 0;
	for (int i = num2.size() - 1; i >= 0; --i)
	{
		string line(num2.size() - 1 - i, '0');
		line += strMulChar(num1, num2[i]);
		resLines.push_back(line);
		if (line.size() > maxLen)
			maxLen = line.size();
	}
	int carry = 0;
	for (int i = 0; i < maxLen; ++i)
	{
		int temp = 0;
		for (string line : resLines)
		{
			int digit = 0;
			if (i >= line.size())
				digit = '0';
			else
				digit = line[i];
			temp += (digit - '0');
		}
		temp += carry;
		res.push_back(temp % 10 + '0');
		carry = temp / 10;
	}
	while (carry)
	{
		res.push_back(carry % 10 + '0');
		carry /= 10;
	}
	std::reverse(res.begin(), res.end());
	return res;
}
