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
	void setLoss(bool loss);
	void setPlayer(Player player);
	Player getPlayer();
	bool getLoss();
	void playGame();
	string playRound();
	string randomEvent();
};

