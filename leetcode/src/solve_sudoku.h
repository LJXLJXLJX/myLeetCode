#pragma once
#include "heads.h"
#include "data_structures.h"

//��ǰ������block��ֵ
std::vector<char> getBlock(const std::vector<std::vector<char>>& board, int i, int j);

//��ǰ���ѡֵ
std::vector<char> optionalValue(const std::vector<std::vector<char>>& board, int i, int j);

//�ݹ���� �������޿�ѡֵ�ڵ� ������һ��ݹ� ����ʣ��սڵ� ���ɹ�
std::vector<std::vector<char>> recurseSudoku(std::vector<std::vector<char>> board, int i, int j, bool &endFlag);

void solveSudoku(std::vector<std::vector<char>>& board);