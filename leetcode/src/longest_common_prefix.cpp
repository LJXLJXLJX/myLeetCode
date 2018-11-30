#include "longest_common_prefix.h"
using namespace std;

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";
	string longestCommonPrefix(strs[0]);
	string temp("");
	int num = strs.size();
	int len = 0;
	for (int i = 0; i < num; i++)
	{
		len = min(strs[i].size(), longestCommonPrefix.size());
		temp = "";
		for (int j = 0; j < len; j++)
		{
			if (longestCommonPrefix[j] == strs[i][j])
			{
				temp.push_back(strs[i][j]);
			}
			else
				break;
		}
		longestCommonPrefix = temp;
		if (longestCommonPrefix == "")
			return "";
	}
	return longestCommonPrefix;
}
