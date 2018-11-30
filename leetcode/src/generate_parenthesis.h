#pragma once
#include "heads.h"
#include "data_structures.h"


void parenthesisGenerator(int left, int right, std::vector<std::string> &res, std::string str);

std::vector<std::string> generateParenthesis(int n);