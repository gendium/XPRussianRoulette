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
	Player player = getPlayer();
	string rng = randomEvent();

	if (rng != "")
	{
		return rng;
	}

	rng = moneySkip();
	player.addRound(1);
	setPlayer(player);

	if (rng == "skip")
	{
		cout << "You skipped a turn!!";
		return "\n";
	}
	else if (rng == "You got 5 btc")
	{
		player.addBTC(5);
		return rng + "\n";
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
	srand(time(0));
	int r = (rand() % 4);
	string temp;
	switch (r) {
	case 0:
		return "";
		break;
	case 1:
		return "You got 5 btc!";
		break;
	case 2:
		return "";
		break;
	case 3:
		return "skip";
		break;
	default:
		return "";
	}
	return "";
}

string Game::moneySkip()
{
	Player tmpPlayer = getPlayer();

	if (tmpPlayer.getBTC() >= 5)
	{
		char choice;
		cout << "you have " << tmpPlayer.getBTC() << " btc\n";
		cout << "Would you like to pay 5 BTC to skip this round? (Y/N)\n";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			tmpPlayer.subtract(5);
			cout << tmpPlayer.getBTC() << endl;
			//setPlayer(tmpPlayer);
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
