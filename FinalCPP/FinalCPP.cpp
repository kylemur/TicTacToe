
//#include <iostream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"
#include "Player.h"
#include <string>
#include <iomanip>
#include <list>
#include <numeric>
#include <iterator>
#include <cmath>

using namespace std;

/* Function Prototypes */
void add_player(list<Player>& player_list);
void display_players(list<Player>& player_list);
list<Player>::iterator find_by_name(list<Player>& player_list, string name);
void find_player_by_name(list<Player>& player_list, string name, string function);
int total_games_played(list<Player>& player_list);
int total_games_won(list<Player>& player_list);
int total_games_tied(list<Player>& player_list);
int total_games_lost(list<Player>& player_list);


int main()
{
	list<Player> player_list;

	string choice;

	do {
		cout << "\n\nMenu: " << endl;
		cout << "0. Quit Program\n";
		cout << "1. Display all players and information\n";
		cout << "2. Add a player\n";
		cout << "3. Play Tic-Tac-Toe\n";
		cout << "4. Find a player by name\n";
		cout << "5. Display total games played by all players\n";
		cout << "6. Display total wins by all players\n";
		cout << "7. Display total ties by all players\n";
		cout << "8. Display total losses by all players\n";
		cout << "Your choice: ";
		string in;
		std::getline(std::cin, in);
		choice = in;

		if (choice == "1") { // Display all players and information
			display_players(player_list);
		}
		else if (choice == "2") { // Add a player
			add_player(player_list);
		}
		else if (choice == "3") { // Play Tic-Tac-Toe
			string playerX, playerO;
			cout << "Enter Player X name: ";
			getline(cin, playerX);
			cout << "Enter Player O name: ";
			getline(cin, playerO);

			TicTacToe game;
			char result = game.playGame();

			find_player_by_name(player_list, playerX, "play");
			find_player_by_name(player_list, playerO, "play");

			if (result == 'X') {
				find_player_by_name(player_list, playerX, "win");
				find_player_by_name(player_list, playerO, "lose");
			}
			else if (result == 'O') {
				find_player_by_name(player_list, playerX, "lose");
				find_player_by_name(player_list, playerO, "win");
			}
			else if (result == 'T') {
				find_player_by_name(player_list, playerX, "tie");
				find_player_by_name(player_list, playerO, "tie");
			}
		}
		else if (choice == "4") { // Find a player by name
			string input;
			cout << "Enter player name to find: ";
			getline(cin, input);
			string name = input;
			find_player_by_name(player_list, name, "display");
		}
		else if (choice == "5") { // Display total games played by all players
			cout << "Total games played by all players: " << total_games_played(player_list) << endl;
		}
		else if (choice == "6") { // Display total wins by all players
			cout << "Total wins by all players: " << total_games_won(player_list) << endl;
		}
		else if (choice == "7") { // Display total ties by all players
			cout << "Total ties by all players: " << total_games_tied(player_list) << endl;
		}
		else if (choice == "8") { // Display total losses by all players
			cout << "Total losses by all players: " << total_games_lost(player_list) << endl;
		}
		else if (choice != "0") {
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != "0");

	cout << "Exiting program." << endl;
	return 0;
}


void add_player(list<Player>& player_list)
{
	string input;
	cout << "Enter player name: ";
	//cin >> name;
	getline(cin, input);
	string name = input;

	Player new_player(name);
	new_player.setName(name);
	player_list.push_back(new_player);
	cout << "Player " << name << " added." << endl;
}

void display_players(list<Player>& player_list)
{
	cout << "Players:" << endl;
	for (Player& player : player_list)
	{
		player.displayPlayerInfo();
	}
	cout << endl;
}

list<Player>::iterator find_by_name(list<Player>& player_list, string name)
{
	list<Player>::iterator it;
	for (it = player_list.begin(); it != player_list.end(); it++)
	{
		if (it->getName() == name)
		{
			return it;
		}
	}
	return it;
}

void find_player_by_name(list<Player>& player_list, string name, string function)
{
	/*string name;
	cout << "Enter player name: ";
	cin >> name;*/
	list<Player>::iterator it = find_by_name(player_list, name);
	if (it != player_list.end() && function == "display")
	{
		cout << "Player found: " << it->getName() << endl;
		it->displayPlayerInfo();
	}
	else if (it != player_list.end() && function == "win")
	{
		it->incrementGamesWon();
		cout << "Player " << name << " won a game." << endl;
	}
	else if (it != player_list.end() && function == "tie")
	{
		it->incrementGamesTied();
		cout << "Player " << name << " tied a game." << endl;
	}
	else if (it != player_list.end() && function == "lose")
	{
		it->incrementGamesLost();
		cout << "Player " << name << " lost a game." << endl;
	}
	else if (it != player_list.end() && function == "play")
	{
		it->incrementGamesPlayed();
		cout << "Player " << name << " played a game." << endl;
	}
	else
	{
		cout << "Player not found." << endl;
	}
}

int total_games_played(list<Player>& player_list)
{
	float total = 0.0f;
	for (Player& player : player_list)
	{
		total += player.getGamesPlayed();
	}

	return ceil(total / 2); // Assuming each game is counted twice, once for each player
}

int total_games_won(list<Player>& player_list)
{
	// Use accumulate to add up balances from all accounts
	/*int total = accumulate(player_list.begin(), player_list.end(), 0, [](int accumulator, Player& a_player) {
		return accumulator + a_player.getGamesWon();
		}
	);*/
	int total = 0;
	for (Player& player : player_list)
	{
		total += player.getGamesWon();
	}
	return total;
}

int total_games_tied(list<Player>& player_list)
{
	/*int total = accumulate(player_list.begin(), player_list.end(), 0, [](auto accumulator, auto& a_player) {
		return accumulator + a_player.getGamesTied();
		}
	);*/

	float total = 0.0f;
	for (Player& player : player_list)
	{
		total += player.getGamesTied();
	}
	return ceil(total / 2); // Assuming each tie is counted twice, once for each player
}

int total_games_lost(list<Player>& player_list)
{
	int total = 0;
	for (Player& player : player_list)
	{
		total += player.getGamesLost();
	}
	return total; 
}
