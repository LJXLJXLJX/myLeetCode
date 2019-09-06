#include "1002_find_common_characters.h"


using namespace std;

std::vector<std::string> commonChars(std::vector<std::string>& A)
{
	vector<vector<int>> table(A.size(), vector<int>(26));
	for (int i = 0; i < A.size(); ++i) {
		for (auto c : A[i]) {
			table[i][c - 'a']++;
		}
	}
	vector<string> ret;
	for (int j = 0; j < 26; ++j) {
		int min = numeric_limits<int>::max();
		for (int i = 0; i < A.size(); ++i) {
			if (table[i][j] < min)
				min = table[i][j];
		}
		for (int k = 0; k < min; ++k) {
			string s;
			s.push_back('a' + j);
			ret.push_back(s);
		}
	}
	return ret;
}
