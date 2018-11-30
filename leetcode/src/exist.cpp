#include "exist.h"

using namespace std;

void existRecurse(bool &res, vector<vector<char>> &board, vector<vector<int>>&stepBoard, string &word, int currentLen, int x, int y) {
	if (res == true)
		return;
	if (currentLen == word.size())
	{
		res = true;
		return;
	}
	for (vector<int> pos : vector<vector<int>>{ { x - 1,y },{ x + 1,y },{ x,y - 1 },{ x,y + 1 } })
	{
		if (pos[0]<0 || pos[0]>board.size() - 1 || pos[1]<0 || pos[1]>board[0].size() - 1
			|| stepBoard[pos[0]][pos[1]] == true || board[pos[0]][pos[1]] != word[currentLen])
			continue;
		else
		{
			stepBoard[pos[0]][pos[1]] = true;
			existRecurse(res, board, stepBoard, word, currentLen + 1, pos[0], pos[1]);
			stepBoard[pos[0]][pos[1]] = false;
		}
	}
}

bool exist(vector<vector<char>>& board, string word) {
	if (word.empty())
		return true;
	vector<vector<int>> stepBoard(board.size(), vector<int>(board[0].size(), 0));
	bool res = false;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == word.front())
			{
				stepBoard[i][j] = true;
				existRecurse(res, board, stepBoard, word, 1, i, j);
				stepBoard[i][j] = false;
			}
			if (res == true)
				return res;
		}
	}
	return res;
}
