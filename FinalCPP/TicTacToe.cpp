#include "TicTacToe.h"
#include <iostream>
#include <string>

using namespace std;

TicTacToe::TicTacToe() : board{ {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }, outcome(' '), turns(0) {};
//{// Constructor initializes the board with numbers 1-9
	// to represent empty spaces.
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	outcome = 'T';
	turns = 0;*/
//}

TicTacToe::~TicTacToe()
{// Destructor
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//	player = ' ';
//	turns = 0;
//	cout << "Game Over!" << endl;
//	cout << "Destructor called." << endl;
}

char TicTacToe::playGame()
{
	while (!isWinner() && !isBoardFull())
	{
		printBoard();
		playerXMove();
		if (isWinner())
		{
			cout << "Player X wins!\n";
			outcome = 'X';
			return outcome;
		} 
		/*else if (isBoardFull())
		{
			cout << "The game was a tie.\n";
			outcome = 'T';
			return outcome;
		}*/

		printBoard();
		playerOMove();
		if (isWinner())
		{
			cout << "Player O wins!\n";
			outcome = 'O';
			return outcome;
		}
		/*else if (isBoardFull())
		{
			cout << "The game was a tie.\n";
			outcome = 'T';
			return outcome;
		}*/

		turns++;
	}

	if (!isWinner() && isBoardFull())
	{
		cout << "The game was a tie.\n";
		outcome = 'T';
		//return outcome;
	}

	return outcome;
}

void TicTacToe::printBoard() const
{
	for (int i = 0; i < 3; i++)
	{
		cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
		if (i != 2)
		{
			cout << "---|---|---" << endl;
		}
	}
	cout << endl;
}

bool TicTacToe::isWinner() const
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return true;
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return true;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return true;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return true;
	}
	return false;
}

bool TicTacToe::isBoardFull() const
{
	return turns == 9;
}

bool TicTacToe::isValidMove(int row, int col) const
{
	return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] != 'X' && board[row][col] != 'O';
}

void TicTacToe::playerXMove()
{
	int row, col;
	cout << "Player X enter your move: ";
	cin >> row >> col;
	row--;
	col--;
	if (isValidMove(row, col))
	{
		board[row][col] = 'X';
	}
	else
	{
		cout << "Invalid move. Try again." << endl;
		playerXMove();
	}
}


void TicTacToe::playerOMove()
{
	int row, col;
	cout << "Player O enter your move: ";
	cin >> row >> col;
	row--;
	col--;
	if (isValidMove(row, col))
	{
		board[row][col] = 'O';
	}
	else
	{
		cout << "Invalid move. Try again." << endl;
		playerOMove();
	}
}
