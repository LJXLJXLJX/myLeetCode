#pragma once
#include "heads.h"

void combineRecurse(std::vector<std::vector<int>>&res, std::vector<int> &combination, int currentLen, int n, int k);

std::vector<std::vector<int>> combine(int n, int k);