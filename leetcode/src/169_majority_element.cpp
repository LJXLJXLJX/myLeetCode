#include "169_majority_element.h"


using namespace std;

int majorityElement(std::vector<int>& nums)
{
	int time = 0;
	int cur = 0;
	for (auto num : nums) {
		if (time == 0) {
			cur = num;
			time++;
		}
		else if (num == cur) {
			time++;
		}
		else {
			time--;
		}
	}
	return cur;
}
