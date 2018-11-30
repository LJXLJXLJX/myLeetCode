#pragma once
#include "heads.h"

void existRecurse(bool &res, std::vector<std::vector<char>> &board, std::vector<std::vector<int>>&stepBoard, std::string &word, int currentLen, int x, int y);

bool exist(std::vector<std::vector<char>>& board, std::string word);