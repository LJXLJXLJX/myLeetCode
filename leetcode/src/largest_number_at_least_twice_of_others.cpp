#include "largest_number_at_least_twice_of_others.h"


using namespace std;

int dominantIndex(std::vector<int>& nums)
{
	if (nums.size() == 1)
		return 0;

	int maxIndex = 0;
	int max = INT_MIN;
	int premax = INT_MIN;

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > max) {
			premax = max;
			max = nums[i];
			maxIndex = i;
		}
		else if (premax <nums[i])
			premax = nums[i];
	}
	if (max < 2 * premax)
		return -1;

	return maxIndex;
}
