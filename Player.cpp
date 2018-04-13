#include "Player.h"
#include <string>


Player::Player(string name)
{
	mName = name;
	mRoundCounter = 0;
	mBtc = 10;
}

string Player::getName()
{
	return mName;
}

void Player::uploadPlayer(ScoreBoard sb)
{
	sb.mScores.insert(pair<string, int>(mName, mRoundCounter));
}

int Player::getRoundCounter()
{
	return mRoundCounter;
}

void Player::addRound(int add)
{
	mRoundCounter += 1;
}

int Player::getBTC()
{
	return mBtc;
}

void Player::addBTC(int append)
{
	mBtc += append;
}

bool Player::subtract(int reduce)
{
	if (reduce > mBtc)
		return false;
	else
	{
		mBtc -= reduce;
		return true;
	}
}

Player::Player()
{
}

Player::~Player()
{
}
