#pragma once
#include "heads.h"
#include "data_structures.h"



void combinationSum2Recurse(
	std::vector<int>::iterator n,
	std::vector<int>& current,
	std::vector<std::vector<int>>& res,
	const std::vector<int>& candidates,
	int target
);


std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);