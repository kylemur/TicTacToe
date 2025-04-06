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
{
	// Destructor
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	outcome = ' ';
	turns = 0;
	cout << "Game Over!" << endl;
	cout << "Destructor called." << endl;
}

void TicTacToe::setPlayers(shared_ptr<Player> playerX, shared_ptr<Player> playerO)
{
	this->playerX = playerX;
	this->playerO = playerO;
}

/*
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
			break;
		} 
		else if (isBoardFull())
		{
			cout << "The game was a tie.\n";
			outcome = 'T';
			return outcome;
		}

		printBoard();
		playerOMove();
		if (isWinner())
		{
			cout << "Player O wins!\n";
			outcome = 'O';
			return outcome;
			break;
		}
		else if (isBoardFull())
		{
			cout << "The game was a tie.\n";
			outcome = 'T';
			return outcome;
		}

		turns++;
	}

	if (!isWinner() && isBoardFull())
	{
		cout << "The game was a tie.\n";
		outcome = 'T';
		return outcome;
	}

	return outcome;
}
*/

void TicTacToe::playGame()
{
	// Play the game until there is a winner or the board is full
	/*cout << "Enter Player X name: ";
	getline(cin, playerX);
	cout << "Enter Player O name: ";
	getline(cin, playerO);*/

	while (!isWinner() && !isBoardFull())
	{
		printBoard();
		playerXMove();
		if (isWinner())
		{
			//playerX->incrementGamesPlayed();
			//playerO->incrementGamesPlayed();
			outcome = 'X';
			cout << "Player X wins!\n";
			//playerX->incrementGamesWon();
			//playerO->incrementGamesLost();
			return;
		}

		turns++;

		if (isBoardFull())
		{
			break;
		}


		printBoard();
		playerOMove();
		if (isWinner())
		{
			//playerX->incrementGamesPlayed();
			//playerO->incrementGamesPlayed();
			outcome = 'O';
			cout << "Player O wins!\n";
			//playerX->incrementGamesLost();
			//playerO->incrementGamesWon();
			return;
		}

		turns++;

		if (isBoardFull())
		{
			break;
		}
	}

	if (!isWinner() && isBoardFull())
	{
		//playerX->incrementGamesPlayed();
		//playerO->incrementGamesPlayed();
		outcome = 'T';
		cout << "The game was a tie.\n";
		//playerX->incrementGamesTied();
		//playerO->incrementGamesTied();
	}
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

char TicTacToe::getOutcome() const
{
	return outcome;
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
