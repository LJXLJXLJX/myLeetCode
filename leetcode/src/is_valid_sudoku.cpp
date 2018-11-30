#include "is_valid_sudoku.h"

using namespace std;

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
	vector<char> block[9];
	for (int i : vector<int>{ 0,1,2 })
	{
		for (int j : vector<int>{ 0,1,2 })
			block[0].push_back(board[i][j]);
		for (int j : vector<int>{ 3,4,5 })
			block[1].push_back(board[i][j]);
		for (int j : vector<int>{ 6,7,8 })
			block[2].push_back(board[i][j]);
	}
	for (int i : vector<int>{ 3,4,5 })
	{
		for (int j : vector<int>{ 0,1,2 })
			block[3].push_back(board[i][j]);
		for (int j : vector<int>{ 3,4,5 })
			block[4].push_back(board[i][j]);
		for (int j : vector<int>{ 6,7,8 })
			block[5].push_back(board[i][j]);
	}
	for (int i : vector<int>{ 6,7,8 })
	{
		for (int j : vector<int>{ 0,1,2 })
			block[6].push_back(board[i][j]);
		for (int j : vector<int>{ 3,4,5 })
			block[7].push_back(board[i][j]);
		for (int j : vector<int>{ 6,7,8 })
			block[8].push_back(board[i][j]);
	}

	for (int i = 0; i < 9; i++)
	{
		vector<char>row, col, blk;
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.' && find(row.begin(), row.end(), board[i][j]) != row.end())
				return false;
			row.push_back(board[i][j]);

			if (board[j][i] != '.' && find(col.begin(), col.end(), board[j][i]) != col.end())
				return false;
			col.push_back(board[j][i]);

			if (block[i][j] != '.'&& find(blk.begin(), blk.end(), block[i][j]) != blk.end())
				return false;
			blk.push_back(block[i][j]);
		}
	}
	return true;
}
