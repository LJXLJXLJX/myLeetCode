//
// Created by ljx on 1/21/19.
//

#include "find_all_numbers_disappeared_in_an_array.h"

using namespace std;

std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int m = abs(nums[i]) - 1; // index start from 0
        nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
    }
    vector<int> res;
    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) res.push_back(i + 1);
    }
    return res;
}
