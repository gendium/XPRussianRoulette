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

		if (choice == 'Y' || choice == 'y')
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

	rng = moneySkip();

	if (rng == "skip")
	{
		cout << "You skipped a turn!!";
		return "\n";
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

string Game::moneySkip()
{
	Player tmpPlayer = getPlayer();

	if (tmpPlayer.getBTC() >= 5)
	{
		char choice;

		cout << "Would you like to pay 5 BTC to skip this round? (Y/N)";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			tmpPlayer.subtract(5);
			cout << tmpPlayer.getBTC();
			setPlayer(tmpPlayer);
			return "skip";
		}
	}
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
