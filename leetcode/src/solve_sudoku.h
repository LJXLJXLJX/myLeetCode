#pragma once
#include "heads.h"
#include "data_structures.h"

//当前点所属block的值
std::vector<char> getBlock(const std::vector<std::vector<char>>& board, int i, int j);

//当前点可选值
std::vector<char> optionalValue(const std::vector<std::vector<char>>& board, int i, int j);

//递归求解 当遇到无可选值节点 返回上一层递归 当无剩余空节点 求解成功
std::vector<std::vector<char>> recurseSudoku(std::vector<std::vector<char>> board, int i, int j, bool &endFlag);

void solveSudoku(std::vector<std::vector<char>>& board);