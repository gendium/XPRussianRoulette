#include <string>
#pragma once
using namespace std;

class Player
{
	int mRoundCounter, mBtc;
	string mName;
public:

	Player();
	string getName();
	int getRoundCounter();
	int getBTC();
	void addBTC(int append);
	bool subtract(int reduce);
	~Player();
};

