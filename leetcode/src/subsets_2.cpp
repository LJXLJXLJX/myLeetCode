#include "subsets_2.h"


using namespace std;

void pickSubRecur(vector<int>& vec, vector<int>& curVec, int len, int head, set<vector<int>>& out) {
	if (vec.size() - head < len - curVec.size())
	{
		curVec.pop_back();
		return;
	}
	if (curVec.size() == len) {
		out.insert(curVec);
		curVec.pop_back();
		return;
	}

	for (int i = head; i < vec.size(); ++i) {
		curVec.push_back(vec[i]);
		pickSubRecur(vec, curVec, len, i + 1, out);
	}
	if (!curVec.empty())
		curVec.pop_back();
}

void pickAllSub(vector<int>&vec, set<vector<int>>& out) {
	for (int len = 1; len <= vec.size(); ++len) {
		vector<int> curVec;
		pickSubRecur(vec, curVec, len, 0, out);
	}

	//*******≤‚ ‘”√*******
	//vector<int> curS;
	//pickSubRecur(vec, curS, 4, 0, out);
	//*****************
}


std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
{
	vector<vector<int>> ret{ {} };
	set<vector<int>> out;
	sort(nums.begin(), nums.end());
	pickAllSub(nums, out);
	for (vector<int> vec : out) {
		ret.push_back(vec);
	}
	return ret;
}
