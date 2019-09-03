#include "392_is_subsequence.h"

bool isSubsequence(std::string s, std::string t)
{
	int is = 0;
	int it = 0;
	int count = 0;
	for (it; it < t.size(); ++it) {
		if (s[is] == t[it]) {
			is++;
			count++;
			continue;
		}
	}
	return s.size() == count;
}
