#include "reverse_string.h"


using namespace std;

void reverseString(std::vector<char>& s)
{
	if (s.empty())
		return;
	for (int i = 0; i < s.size() / 2; ++i) {
		swap(s[i], s[s.size() - 1 - i]);
	}
}
