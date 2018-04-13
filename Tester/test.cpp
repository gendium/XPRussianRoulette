#include "pch.h"
#include "../ScoreBoard.h"

using namespace std;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//Alec
//Write Test for Game.playRound
TEST(TestCaseName1, TestName1) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

//Alec
//User offered to pay money to skip a round (Game.moneySkip)
TEST(TestCaseName2, TestName2) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
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
TEST(TestCaseName3, TestName3) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}