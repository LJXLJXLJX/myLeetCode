#pragma once
#include "heads.h"

void subsetRecurse(std::vector<std::vector<int>>&res, std::vector<int>&subset, int currentIndex, std::vector<int> &nums);

std::vector<std::vector<int>> subsets(std::vector<int>& nums);