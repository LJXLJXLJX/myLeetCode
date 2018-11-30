#include "solve_n_queens.h"

using namespace std;

bool vailidQ(const vector<string> &board, int i, int j)
{
	for (int m = 0; m < board.size(); ++m)
		if (board[i][m] == 'Q' || board[m][j] == 'Q')
			return false;
	int m = i, n = j;
	while (m > 0 && n > 0)
		if (board[--m][--n] == 'Q')
			return false;
	m = i, n = j;
	while (m < board.size() - 1 && n < board.size() - 1)
		if (board[++m][++n] == 'Q')
			return false;
	m = i, n = j;
	while (m > 0 && n < board.size() - 1)
		if (board[--m][++n] == 'Q')
			return false;
	m = i, n = j;
	while (m < board.size() - 1 && n >0)
		if (board[++m][--n] == 'Q')
			return false;
	return true;
}
//the case n>3
void solveNQueensDFS(vector<string> &board, int row, int queenNum, vector< vector<string>> &res)
{
	if (queenNum == 0)
	{
		res.push_back(board);
		return;
	}
	for (int j = 0; j < board.size(); ++j)
	{
		if (vailidQ(board, row, j))
		{
			board[row][j] = 'Q';
			solveNQueensDFS(board, row + 1, queenNum - 1, res);
			board[row][j] = '.';
		}
	}
	return;
}


vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> board = { (const unsigned int)n,string(n,'.') };
	int row = 0;
	if (n <= 3)
	{
		if (n == 1)
			res.push_back(vector<string>{"Q"});
		return res;
	}
	else
		solveNQueensDFS(board, row, n, res);
	return res;
}

int totalNQueens(int n) {
	auto res = solveNQueens(n);
	return res.size();
}