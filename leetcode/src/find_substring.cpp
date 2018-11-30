#include "find_substring.h"

using namespace std;

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
	vector<int> res;
	int num = words.size();
	int len = words[0].size();
	if (num <= 0 || num * len > s.size())
		return res;

	unordered_map<string, int> wordNum = {};
	for (string word : words)
	{
		wordNum[word]++;
	}

	for (int i = 0; i <= s.size() - num * len; i++)
	{
		int wordAppeardNum = 0;
		unordered_map<string, int>wordRemained(wordNum);
		for (int j = i; j < s.size(); )
		{
			string potentialWord = s.substr(j, len);
			if (find(words.begin(), words.end(), potentialWord) != words.end())	//potential word is in words
			{
				wordAppeardNum++;
				wordRemained[potentialWord]--;
				if (wordRemained[potentialWord] < 0)
					break;
				else
				{
					if (wordAppeardNum == num)	//get a substr in res
					{
						res.push_back(i);
						break;
					}
					else
						j += len;
				}
			}
			else
				break;
		}
	}
	return res;
}
