#include "find_median_sorted_arrays.h"

using namespace std;

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	double median = 0;
	int len = nums1.size() + nums2.size();
	vector<int> nums(len);
	for (int& num : nums)
	{
		if (nums1.size() == 0)
		{
			num = nums2[0];
			nums2.erase(nums2.begin());
		}
		else if (nums2.size() == 0)
		{
			num = nums1[0];
			nums1.erase(nums1.begin());
		}
		else
		{
			if (nums1[0] <= nums2[0])
			{
				num = nums1[0];
				nums1.erase(nums1.begin());
			}
			else
			{
				num = nums2[0];
				nums2.erase(nums2.begin());
			}
		}

	}
	if (len % 2 == 1)
		median = nums[len / 2];
	else
		median = ((double)nums[len / 2 - 1] + (double)nums[len / 2]) / 2;
	return median;
}
