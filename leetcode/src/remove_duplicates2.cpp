#include "remove_duplicates2.h"

using namespace std;


int removeDuplicates2(vector<int>& nums) {
	int n = nums.size(), count = 0;
	for (int i = 2; i < n; i++)
		if (nums[i] == nums[i - 2 - count]) count++;
		else nums[i - count] = nums[i];
		return n - count;
}
