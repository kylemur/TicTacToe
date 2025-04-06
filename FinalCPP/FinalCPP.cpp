
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
void display_players(const list<Player>& player_list);
list<Player>::iterator find_by_name(list<Player>& player_list, const string& name);
void find_player_by_name(list<Player>& player_list, const string& name);
void updatePlayerStats(list<Player>& playerList, const string& name, const string& action);
int totalGamesPlayed(const list<Player>& player_list);
int totalGamesWon(const list<Player>& player_list);
int totalGamesTied(const list<Player>& player_list);
int totalGamesLost(const list<Player>& player_list);


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
			string playerXName, playerOName;
			cout << "Enter Player X name: ";
			getline(cin, playerXName);
			cout << "Enter Player O name: ";
			getline(cin, playerOName);

			auto playerX = find_by_name(player_list, playerXName);
			auto playerO = find_by_name(player_list, playerOName);

			if (playerX == player_list.end() || playerO == player_list.end()) {
				cout << "One or both players not found. Please add the players first." << endl;
				continue;
			}

			TicTacToe game;
			game.setPlayers(make_shared<Player>(*playerX), make_shared<Player>(*playerO));
			game.playGame();


			/*updatePlayerStats(player_list, playerX, "played");
			updatePlayerStats(player_list, playerO, "played");

			if (result == 'X') {
				updatePlayerStats(player_list, playerX, "won");
				updatePlayerStats(player_list, playerO, "lost");
			}
			else if (result == 'O') {
				updatePlayerStats(player_list, playerX, "lost");
				updatePlayerStats(player_list, playerO, "won");
			}
			else if (result == 'T') {
				updatePlayerStats(player_list, playerX, "tied");
				updatePlayerStats(player_list, playerO, "tied");
			}*/

			updatePlayerStats(player_list, playerXName, "played");
			updatePlayerStats(player_list, playerOName, "played");

			if (game.getOutcome() == 'X') {
				updatePlayerStats(player_list, playerXName, "won");
				updatePlayerStats(player_list, playerOName, "lost");
			}
			else if (game.getOutcome() == 'O') {
				updatePlayerStats(player_list, playerXName, "lost");
				updatePlayerStats(player_list, playerOName, "won");
			}
			else if (game.getOutcome() == 'T') {
				updatePlayerStats(player_list, playerXName, "tied");
				updatePlayerStats(player_list, playerOName, "tied");
			}

			// choice = "1"; // Set choice to 1 to display players after the game
		}
		else if (choice == "4") { // Find a player by name
			string input;
			cout << "Enter player name to find: ";
			getline(cin, input);
			string name = input;
			find_player_by_name(player_list, name);
		}
		else if (choice == "5") { // Display total games played by all players
			cout << "Total games played by all players: " << totalGamesPlayed(player_list) << endl;
		}
		else if (choice == "6") { // Display total wins by all players
			cout << "Total wins by all players: " << totalGamesWon(player_list) << endl;
		}
		else if (choice == "7") { // Display total ties by all players
			cout << "Total ties by all players: " << totalGamesTied(player_list) << endl;
		}
		else if (choice == "8") { // Display total losses by all players
			cout << "Total losses by all players: " << totalGamesLost(player_list) << endl;
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

void display_players(const list<Player>& player_list)
{
	cout << "Players:" << endl;
	for (const Player& player : player_list)
	{
		player.displayPlayerInfo();
	}
	cout << endl;
}

list<Player>::iterator find_by_name(list<Player>& player_list, const string& name)
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

//void find_player_by_name(list<Player>& player_list, const string& name, const string& function)
//{
//	/*string name;
//	cout << "Enter player name: ";
//	cin >> name;*/
//	list<Player>::iterator it = find_by_name(player_list, name);
//	if (it != player_list.end() && function == "display")
//	{
//		cout << "Player found: " << it->getName() << endl;
//		it->displayPlayerInfo();
//	}
//	else if (it != player_list.end() && function == "win")
//	{
//		it->incrementGamesWon();
//		cout << "Player " << name << " won a game." << endl;
//	}
//	else if (it != player_list.end() && function == "tie")
//	{
//		it->incrementGamesTied();
//		cout << "Player " << name << " tied a game." << endl;
//	}
//	else if (it != player_list.end() && function == "lose")
//	{
//		it->incrementGamesLost();
//		cout << "Player " << name << " lost a game." << endl;
//	}
//	else if (it != player_list.end() && function == "play")
//	{
//		it->incrementGamesPlayed();
//		cout << "Player " << name << " played a game." << endl;
//	}
//	else
//	{
//		cout << "Player not found." << endl;
//	}
//}

void find_player_by_name(list<Player>& player_list, const string& name)
{
	list<Player>::iterator it = find_by_name(player_list, name);
	if (it != player_list.end())
	{
		cout << "Player found: " << it->getName() << endl;
		it->displayPlayerInfo();
	}
	else
	{
		cout << "Player not found." << endl;
	}
}

void updatePlayerStats(list<Player>& playerList, const string& name, const string& action) 
{
	auto it = find_by_name(playerList, name);
	if (it != playerList.end()) {
		if (action == "won") it->incrementGamesWon();
		else if (action == "tied") it->incrementGamesTied();
		else if (action == "lost") it->incrementGamesLost();
		else if (action == "played") it->incrementGamesPlayed();
		cout << "Player " << name << " " << action << " a game." << endl;
	}
	else {
		cout << "Player not found." << endl;
	}
}


//int total_games_played(list<Player>& player_list)
//{
//	float total = 0.0f;
//	for (Player& player : player_list)
//	{
//		total += player.getGamesPlayed();
//	}
//
//	return ceil(total / 2); // Assuming each game is counted twice, once for each player
//}

int totalGamesPlayed(const list<Player>& playerList) {
	return accumulate(playerList.begin(), playerList.end(), 0, [](int total, const Player& player) {
		return total + player.getGamesPlayed();
		}) / 2; // Assuming each game is counted twice, once for each player
}


//int total_games_won(list<Player>& player_list)
//{
//	// Use accumulate to add up balances from all accounts
//	/*int total = accumulate(player_list.begin(), player_list.end(), 0, [](int accumulator, Player& a_player) {
//		return accumulator + a_player.getGamesWon();
//		}
//	);*/
//
//	int total = 0;
//	for (Player& player : player_list)
//	{
//		total += player.getGamesWon();
//	}
//	return total;
//}

int totalGamesWon(const list<Player>& playerList) {
	return accumulate(playerList.begin(), playerList.end(), 0, [](int total, const Player& player) {
		return total + player.getGamesWon();
		});
}


int totalGamesTied(const list<Player>& player_list)
{
	/*int total = accumulate(player_list.begin(), player_list.end(), 0, [](auto accumulator, auto& a_player) {
		return accumulator + a_player.getGamesTied();
		}
	);*/

	float total = 0.0f;
	for (const Player& player : player_list)
	{
		total += player.getGamesTied();
	}
	return ceil(total / 2); // Assuming each tie is counted twice, once for each player
}

int totalGamesLost(const list<Player>& player_list)
{
	int total = 0;
	for (const Player& player : player_list)
	{
		total += player.getGamesLost();
	}
	return total; 
}
