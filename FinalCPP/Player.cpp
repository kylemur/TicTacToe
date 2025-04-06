#include "Player.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void Player::setName(string name)
{
	this->name = name;
}

string Player::getName() const
{
	return name;
}

void Player::setGamesPlayed(int games_played)
{
	this->games_played = games_played;
}

void Player::incrementGamesPlayed()
{
	this->games_played++;
}

int Player::getGamesPlayed() const
{
	return games_played;
}

void Player::setGamesWon(int games_won)
{
	this->games_won = games_won;
}

void Player::incrementGamesWon()
{
	this->games_won++;
}

int Player::getGamesWon() const
{
	return games_won;
}

void Player::setGamesTied(int games_tied)
{
	this->games_tied = games_tied;
}

void Player::incrementGamesTied()
{
	this->games_tied++;
}

int Player::getGamesTied() const
{
	return games_tied;
}

void Player::setGamesLost(int games_lost)
{
	this->games_lost = games_lost;
}

void Player::incrementGamesLost()
{
	this->games_lost++;
}

int Player::getGamesLost() const
{
	return games_lost;
}

void Player::displayPlayerInfo() const
{
	cout << "Name: " << name << " Games Played: " << games_played << " Wins: " << games_won << " Ties: " << games_tied << " Losses: " << games_lost << endl;
}