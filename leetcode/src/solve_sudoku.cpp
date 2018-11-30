#include "solve_sudoku.h"

using namespace std;

std::vector<char> getBlock(const std::vector<std::vector<char>>& board, int i, int j)
{
	vector<char>res;
	if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
		for (int m = 0; m < 3; m++)
			for (int n = 0; n < 3; n++)
				res.push_back(board[m][n]);

	else if (i >= 0 && i <= 2 && j >= 3 && j <= 5)
		for (int m = 0; m < 3; m++)
			for (int n = 3; n < 6; n++)
				res.push_back(board[m][n]);

	else if (i >= 0 && i <= 2 && j >= 6 && j <= 8)
		for (int m = 0; m < 3; m++)
			for (int n = 6; n < 9; n++)
				res.push_back(board[m][n]);

	else if (i >= 3 && i <= 5 && j >= 0 && j <= 2)
		for (int m = 3; m < 6; m++)
			for (int n = 0; n < 3; n++)
				res.push_back(board[m][n]);

	else if (i >= 3 && i <= 5 && j >= 3 && j <= 5)
		for (int m = 3; m < 6; m++)
			for (int n = 3; n < 6; n++)
				res.push_back(board[m][n]);

	else if (i >= 3 && i <= 5 && j >= 6 && j <= 8)
		for (int m = 3; m < 6; m++)
			for (int n = 6; n < 9; n++)
				res.push_back(board[m][n]);

	else if (i >= 6 && i <= 8 && j >= 0 && j <= 2)
		for (int m = 6; m < 9; m++)
			for (int n = 0; n < 3; n++)
				res.push_back(board[m][n]);

	else if (i >= 6 && i <= 8 && j >= 3 && j <= 5)
		for (int m = 6; m < 9; m++)
			for (int n = 3; n < 6; n++)
				res.push_back(board[m][n]);

	else if (i >= 6 && i <= 8 && j >= 6 && j <= 8)
		for (int m = 6; m < 9; m++)
			for (int n = 6; n < 9; n++)
				res.push_back(board[m][n]);
	return res;
}

std::vector<char> optionalValue(const std::vector<std::vector<char>>& board, int i, int j)
{
	vector<char> optionalValue = {};
	vector<char>block = getBlock(board, i, j);
	for (char c : vector<char>{ '1','2','3','4','5','6','7','8','9' })
	{
		bool continueFlag = false;
		for (int k = 0; k < 9; k++)
			if (c == board[i][k])
			{
				continueFlag = true;
				break;
			}
		if (continueFlag)
			continue;
		for (int k = 0; k < 9; k++)
			if (c == board[k][j])
			{
				continueFlag = true;
				break;
			}
		if (continueFlag)
			continue;
		for (int k = 0; k < 9; k++)
			if (c == block[k])
			{
				continueFlag = true;
				break;
			}
		if (continueFlag)
			continue;
		optionalValue.push_back(c);
	}
	return optionalValue;
}

std::vector<std::vector<char>> recurseSudoku(std::vector<std::vector<char>> board, int i, int j, bool & endFlag)
{
	for (i; i < 9; i++, j = 0)
	{
		for (j; j < 9; j++)
		{
			if (board[i][j] != '.')
				continue;
			vector<char> candidate = optionalValue(board, i, j);
			if (candidate.empty())
				return board;
			vector<vector<char>>lastBoard = board;
			for (char c : candidate)
			{
				board[i][j] = c;
				vector<vector<char>>Localboard = recurseSudoku(board, i, j, endFlag);
				if (endFlag || (i == 8 && j == 8))
					return Localboard;
			}
			return lastBoard;
		}
	}
	endFlag = true;
	return board;
}

void solveSudoku(vector<vector<char>>& board)
{
	bool endFlag = false;
	board = recurseSudoku(board, 0, 0, endFlag);
}



