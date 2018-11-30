#include "merge_sorted_array.h"

using namespace std;

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	int index1 = m - 1, index2 = n - 1, index = nums1.size() - 1;
	while (index1 >= 0 && index2 >= 0)
		nums1[index--] = nums1[index1] >= nums2[index2] ? nums1[index1--] : nums2[index2--];
	while (index2 >= 0)
		nums1[index--] = nums2[index2--];
}
