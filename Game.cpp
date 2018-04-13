#pragma once
#include "Game.h"
#include <string>
#include <iostream>

using namespace std;

Game::Game()
{
}


Game::~Game()
{
}

Player Game::getPlayer()
{
	return mPlayer;
}

void Game::choosePlayer()
{
	string playerName;
	cout << "Enter player name:  ";
	getline(cin, playerName);
	Player player(playerName);
	setPlayer(player);
}

void Game::playGame()
{
	char choice = 'y';
	choosePlayer();
	
	while ((choice != 'N' && choice != 'n') && !getLoss())
	{
		cout << "\nWould you like to press your luck?!?!? (Y/N)\n";
		cin >> choice;

		if (choice == 'y' || choice == 'y')
			cout << playRound() << endl;
	}
	
	cout << "Thanks for playing!!\n";

}

string Game::playRound()
{
	string rng = randomEvent();

	if (rng != "")
	{
		return rng;
	}

	else
	{
		setLoss(true);
		return "Sorry, you Lose";
	}
}

string Game::randomEvent()
{
	//Handle any of the math that is happening to player values here
	return "";
}

void Game::setLoss(bool loss)
{
	mLoss = loss;
}

bool Game::getLoss()
{
	return mLoss;
}

void Game::setPlayer(Player player)
{
	mPlayer = player;
}
