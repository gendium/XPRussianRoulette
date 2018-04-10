#include "Player.h"



Player::Player()
{
	mName = "";
	mRoundCounter = mBtc = 0;
}

string Player::getName()
{
	return mName;
}

int Player::getRoundCounter()
{
	return mRoundCounter;
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

Player::~Player()
{
}
