#pragma once
#include "ScoreBoard.h"
#include <string>

using namespace std;

class Player
{
	int mRoundCounter, mBtc;
	string mName;
public:
	Player();
	Player(string name);
	~Player();
	string getName();
	void uploadPlayer(ScoreBoard sb);
	int getRoundCounter();
	void addRound(int add);
	int getBTC();
	void addBTC(int append);
	bool subtract(int reduce);
	
};

