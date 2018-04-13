#include "pch.h"
#include "../ScoreBoard.h"
#include "../Player.h"
#include "../Game.h"

using namespace std;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//Alec
//Write Test for Game.playRound
TEST(TestRoundOut, TestSkip) {
	Game mGame;
	Player mPlayer("test");
	mGame.setPlayer(mPlayer);
	string returned = mGame.playRound("skip");
	ASSERT_EQ(returned, "You skipped a turn!!\n");
}

TEST(TestRoundOut, TestLoss) {
	Game mGame;
	Player mPlayer("test");
	mGame.setPlayer(mPlayer);
	string returned = mGame.playRound("");
	ASSERT_EQ(returned, "Sorry, you Lose\n");
}

TEST(TestRoundOut, TestBTC) {
	Game mGame;
	Player mPlayer("test");
	mGame.setPlayer(mPlayer);
	string returned = mGame.playRound("You got 5 btc");
	ASSERT_EQ(returned, "You got 5 btc\n");
}

//Alec
//User offered to pay money to skip a round (Game.moneySkip)
TEST(MoneySkip, checkOut) {
	Game mGame;
	Player mPlayer("test");
	mPlayer.addBTC(5);
	mGame.setPlayer(mPlayer);
	ASSERT_EQ("skip", mGame.moneySkip());
}

//Tony
//A high score board will be displayed
TEST(ScoreBoardTest, correctOutput) {
	ScoreBoard sb;
	string output = "Test";
	ASSERT_EQ("Alec,18\nTony,22\nBrian,55\n", sb.displayScoreBoard());
}

//Tony
//Random Event
TEST(RandomEvent, TestNum1) {
	Game mGame;
	ASSERT_EQ("", mGame.randomEvent(0));
	ASSERT_EQ("You got 5 btc!", mGame.randomEvent(1));
	ASSERT_EQ("", mGame.randomEvent(2));
	ASSERT_EQ("skip", mGame.randomEvent(3));
	ASSERT_EQ("", mGame.randomEvent(45));

}