#include "length_of_last_word.h"

using namespace std;

int lengthOfLastWord(string s) {
	int res = 0;
	bool wordZone = false;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (wordZone == false && s[i] != ' ')
		{
			wordZone = true;
			++res;
			continue;
		}
		if (wordZone && s[i] == ' ')
			break;
		if (wordZone)
			++res;
	}
	return res;
}
