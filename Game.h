#pragma once
#include "Player.h"

class Game
{
private:
	Player mPlayer;
	bool mLoss = false;

public:
	Game();
	~Game();
	void choosePlayer();
	void Game::setLoss(bool loss);
	void setPlayer(Player player);
	Player Game::getPlayer();
	bool Game::getLoss();
	void Game::playGame();
	string Game::playRound();
	string Game::randomEvent();
};

