#pragma once
#include "heads.h"
#include "data_structures.h"

void recurseCombinationSum(std::vector<std::vector<int>>&res, std::vector<int>&candidates, std::vector<int>combination, int target, int begin);


std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);