#pragma once
#include "heads.h"

std::vector<int> findMaxCrossingSubarray(std::vector<int> &nums, int low, int mid, int high);

std::vector<int> findMaxSubarray(std::vector<int> &nums, int low, int high);

int maxSubArray(std::vector<int>& nums);

//leetcode最快方法 非常巧妙
int _maxSubArray(std::vector<int>& nums);