#include "remove_duplicates.h"

int removeDuplicates(std::vector<int>& nums)
{
	int a = 1;
	//��Ѱ���ظ�����ǰ�󲻵ȣ�
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] != nums[i - 1]) {
			nums[a++] = nums[i];
		}
	}
	return a > nums.size() ? nums.size() : a;
}
