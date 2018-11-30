#pragma once
#include "heads.h"

bool vailidQ(const std::vector<std::string> &board, int i, int j);

//the case n>3
void solveNQueensDFS(std::vector<std::string> &board, int row, int queenNum, std::vector<std::vector<std::string>> &res);

std::vector<std::vector<std::string>> solveNQueens(int n);

int totalNQueens(int n);