#include "letter_combinations.h"

using namespace std;

std::vector<std::string> letterCombinations(std::string digits)
{
	vector<string> res;
	vector<string> strsAfterEveryInput;
	vector<string> keyTable({ " ","","abc","def","ghi",
		"jkl","mno","pqrs","tuv","wxyz" });
	char index = 0;
	for (char digit : digits)
	{
		index = digit - '0';
		auto temp(strsAfterEveryInput);
		for (char c : keyTable[index])
		{
			if (temp.empty())
			{
				string resStr("");
				resStr.push_back(c);
				strsAfterEveryInput.push_back(resStr);
				continue;
			}
			for (string resStr : temp)
			{
				resStr.push_back(c);
				strsAfterEveryInput.push_back(resStr);
			}
		}
	}
	for (string s : strsAfterEveryInput)
		if (s.size() == digits.size())
			res.push_back(s);
	return res;
}
