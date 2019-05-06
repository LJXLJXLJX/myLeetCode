#include "119_pascals_triangle_2.h"


using namespace std;

std::vector<int> getRow(int rowIndex)
{
	vector<int>ret;
	list<int> last = { 1 };
	if (rowIndex == 0) {
		ret.assign(last.begin(), last.end());
		return ret;
	}
	for (int i = 1; i <= rowIndex; ++i) {
		list<int> cur;
		for (auto it = last.begin(); it != prev(last.end()); ++it) {
			cur.push_back(*it + *next(it));
		}
		cur.push_front(1);
		cur.push_back(1);
		last = cur;
	}

	ret.assign(last.begin(), last.end());
	return ret;
}
