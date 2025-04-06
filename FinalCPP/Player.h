#pragma once

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Player
{
private:
	string name;
	int games_played;
	int games_won;
	int games_tied;
	int games_lost;
public:
	Player() : name(""), games_played(0), games_won(0), games_tied(0), games_lost(0) {};
	Player(string a_name) : name(a_name), games_played(0), games_won(0), games_tied(0), games_lost(0) {};
	~Player();
	void setName(string name);
	string getName() const;
	void setGamesPlayed(int games_played);
	void incrementGamesPlayed();
	int getGamesPlayed() const;
	void setGamesWon(int games_won);
	void incrementGamesWon();
	int getGamesWon() const;
	void setGamesTied(int games_tied);
	void incrementGamesTied();
	int getGamesTied() const;
	void setGamesLost(int games_lost);
	void incrementGamesLost();
	int getGamesLost() const;
	void displayPlayerInfo() const;
};

