#include "zigzag_convert.h"

using namespace std;

std::string convert(std::string s, int numRows)
{
	if (s.size() == 0)
		return "";
	string result("");
	int len = s.size();
	int idealLen = numRows;
	vector<int> index({});
	while (idealLen < len)
	{
		if (numRows == 1)
			idealLen = len;
		else if (numRows == 2)
		{
			while (idealLen < len)
				idealLen += 2;
		}
		else
			idealLen += numRows * 2 - 2;
	}
	int diff = idealLen - len;
	while (diff--)
	{
		s += "#";
	}
	int numInRow1 = 0;
	if (numRows == 1)
		numInRow1 = idealLen;
	else
		numInRow1 = (idealLen + numRows - 2) / (2 * numRows - 2);//长竖的数量
	int interval = 0;//长竖的间隔
	if (numRows == 1)
		interval = 1;
	else
		interval = 2 * (numRows - 1);
	for (int i = 0; i < numRows; i++)
	{
		if (i == 0 || i == numRows - 1)
		{
			for (int j = 0; j < numInRow1; j++)
			{
				index.push_back(i + interval * j);
			}
		}
		else
		{
			for (int j = 0; j < numInRow1; j++)
			{
				if (j == 0)
				{
					index.push_back(i);
				}
				else
				{
					index.push_back(i + interval * j - 2 * i);
					index.push_back(i + interval * j);
				}
			}
		}
	}
	for (int i : index)
	{
		result += s[i];
	}
	while (result.find("#") != -1)
	{
		result.erase(result.begin() + result.find("#"));
	}
	return result;
}
