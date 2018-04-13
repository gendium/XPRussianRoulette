#pragma once
#include "Player.h"
#include <ctime>
#include <cstdlib>

using namespace std;
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
	string playRound(string choice);
	string randomEvent(int r);
	string moneySkip();
};

