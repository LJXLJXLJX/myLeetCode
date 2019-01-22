//
// Created by ljx on 1/21/19.
//

#include "find_the_duplicate_number.h"

int findDuplicate(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[abs(nums[i])]<0)
            return abs(nums[i]);
        nums[abs(nums[i]) ] *= -1;
    }
}
