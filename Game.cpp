#pragma once
#include "Game.h"
#include "Scoreboard.h"
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
	ScoreBoard sb;
	srand(time(0));
	int r;
	choosePlayer();
	
	while ((choice != 'N' && choice != 'n') && !getLoss())
	{
		cout << "\nWould you like to press your luck?!?!? (Y/N)\n Or Display the Score Board? (S)\n";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			r = (rand() % 4);
			string rng = randomEvent(r);
			if (rng == "")
				rng = moneySkip();
			cout << playRound(rng) << endl;
		}
			

		else if (choice == 'S' || choice == 's')
			cout << sb.displayScoreBoard() << endl;
	}
	
	cout << "Thanks for playing!!\n";
	cout << "Would you like to upload your score? (Y)\n";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		ScoreBoard sb;
		cout << "Uploading Scores...\n";
		sb.getScores();
		sb.mScores.insert(pair<string, int>(getPlayer().getName(), getPlayer().getRoundCounter()));
		sb.uploadScoreBoard();
	}
	else {
		cout << "FINE!\n";
	}

}

string Game::playRound(string choice)
{
	Player player = getPlayer();
	
	player.addRound(1);

	if (choice == "skip")
	{
		setPlayer(player);
		return "You skipped a turn!!\n";
	}
	else if (choice == "You got 5 btc")
	{
		player.addBTC(5);
		setPlayer(player);
		return choice + "\n";
	}

	else 
	{
		setLoss(true);
		setPlayer(player);
		return "Sorry, you Lose\n";
	}

}

string Game::randomEvent(int r)
{
	//Handle any of the math that is happening to player values here
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
		char choice = 'Y';
		cout << "you have " << tmpPlayer.getBTC() << " btc\n";
		cout << "Would you like to pay 5 BTC to skip this round? (Y/N)\n";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			tmpPlayer.subtract(5);
			cout << "You have " << tmpPlayer.getBTC() << " BTC left\n";
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
