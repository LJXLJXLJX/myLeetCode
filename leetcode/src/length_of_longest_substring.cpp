#include "length_of_longest_substring.h"


using namespace std;

int lengthOfLongestSubstring(std::string s)
{
	int len = s.size();
	int count = 0;
	int max = 0;
	vector<char> chars = {};
	for (int i = 0; i < len; i++)
	{
		count = 1;
		chars = { s[i] };
		for (int j = i + 1; j < len; j++)
		{
			if (find(chars.begin(), chars.end(), s[j]) != chars.end())
				break;
			chars.push_back(s[j]);
			count++;
		}
		if (count > max)
			max = count;
	}
	return max;
}
