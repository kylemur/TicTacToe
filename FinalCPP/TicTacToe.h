#pragma once
#include <string>
#include <memory>
#include "Player.h"

using namespace std;

class TicTacToe
{
private:
	char board[3][3];
	char outcome;
	int turns;
	shared_ptr<Player> playerX;
	shared_ptr<Player> playerO;
public:
	TicTacToe();
	~TicTacToe();
	void playGame();
	void printBoard() const;
	char getOutcome() const;
	bool isWinner() const;
	bool isBoardFull() const;
	bool isValidMove(int row, int col) const;
	void playerXMove();
	void playerOMove();
	void setPlayers(shared_ptr<Player> playerX, shared_ptr<Player> playerO);
};

