#pragma once
#include <string>

using namespace std;

class TicTacToe
{
private:
	char board[3][3];
	char outcome;
	int turns;
public:
	TicTacToe();
	~TicTacToe();
	char playGame();
	void printBoard() const;
	bool isWinner() const;
	bool isBoardFull() const;
	bool isValidMove(int row, int col) const;
	void playerXMove();
	void playerOMove();
	//void computerMove();
};

