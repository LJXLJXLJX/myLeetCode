#include "merge.h"

using namespace std;

vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() <= 1)
		return intervals;
	sort(intervals.begin(), intervals.end(), compareIntervals);
	vector<Interval> res({ intervals[0] });
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].start <= res.back().end)
			res.back().end = max(res.back().end, intervals[i].end);
		else
			res.push_back(intervals[i]);
	}
	return res;
}
