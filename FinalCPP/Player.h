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
	Player() : name(""), games_played(0), games_won(0), games_tied(0), games_lost(0) {}
	Player(string a_name) : name(a_name), games_played(0), games_won(0), games_tied(0), games_lost(0) {}
	~Player() {}
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

/*
class Player
{
private:
    string name;
    int games_played;
    int games_won;
    int games_tied;
    int games_lost;
public:
    Player() : name(""), games_played(0), games_won(0), games_tied(0), games_lost(0) {}
    Player(string a_name) : name(a_name), games_played(0), games_won(0), games_tied(0), games_lost(0) {}
    ~Player() {}
    void setName(string name) { this->name = name; }
    string getName() const { return name; }
    void setGamesPlayed(int games_played) { this->games_played = games_played; }
    void incrementGamesPlayed() { games_played++; }
    int getGamesPlayed() const { return games_played; }
    void setGamesWon(int games_won) { this->games_won = games_won; }
    void incrementGamesWon() { games_won++; }
    int getGamesWon() const { return games_won; }
    void setGamesTied(int games_tied) { this->games_tied = games_tied; }
    void incrementGamesTied() { games_tied++; }
    int getGamesTied() const { return games_tied; }
    void setGamesLost(int games_lost) { this->games_lost = games_lost; }
    void incrementGamesLost() { games_lost++; }
    int getGamesLost() const { return games_lost; }
    void displayPlayerInfo() const {
        cout << "Name: " << name << " Games Played: " << games_played << " Wins: " << games_won << " Ties: " << " Losses: " << games_lost << endl;
    }
};
*/
