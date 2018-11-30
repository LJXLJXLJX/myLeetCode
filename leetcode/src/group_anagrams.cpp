#include "group_anagrams.h"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	unordered_map<string, vector<string>> map;
	for (string str : strs)
	{
		string sortedStr(str);
		sort(sortedStr.begin(), sortedStr.end());
		map[sortedStr].push_back(str);
	}
	for (auto element : map)
		res.push_back(element.second);
	return res;
}
