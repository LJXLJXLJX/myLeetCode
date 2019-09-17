#include "128_longest_consecutive_sequence.h"

using namespace std;

int longestConsecutive(std::vector<int>& nums)
{
	if (nums.empty())
		return 0;
	unordered_set<int> num_set;
	for (auto num : nums)
		num_set.insert(num);
	int max_len = 1;
	for (auto num : num_set) {
		if (num_set.find(num - 1) == num_set.end()) {
			int cur = num;
			int len = 1;
			while (num_set.find(cur + 1) != num_set.end()) {
				len++;
				if (len > max_len)
					max_len = len;
				cur++;
			}
		}
	}
	return max_len;
}
