#include "search2.h"


using namespace std;


bool bsearch(int l, int r, vector<int> nums, int target) {
	if (l>r) return 0;
	int mid = (l + r) / 2;
	if (nums[mid] == target) return 1;
	if (nums[l] == nums[mid] || nums[mid] == nums[r]) return (bsearch(l, mid - 1, nums, target) | bsearch(mid + 1, r, nums, target));
	else {
		if (nums[l] < nums[mid]) {
			if (target >= nums[l] && target < nums[mid]) {
				return bsearch(l, mid - 1, nums, target);
			}
			else {
				return bsearch(mid + 1, r, nums, target);
			}
		}
		else {
			if (target > nums[mid] && target <= nums[r]) {
				return bsearch(mid + 1, r, nums, target);
			}
			else {
				return bsearch(l, mid - 1, nums, target);
			}
		}
	}
	return 0;
}


bool search2(std::vector<int>& nums, int target)
{
	if (!nums.size()) return 0;
	int l = 0, r = nums.size() - 1;
	return bsearch(l, r, nums, target);
}
