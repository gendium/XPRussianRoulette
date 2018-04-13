#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <map>

using namespace std;
class ScoreBoard
{
public:
	map<string, int> mScores;
	ScoreBoard();
	void uploadScoreBoard();
	void getScores();
	string displayScoreBoard();
	~ScoreBoard();
};

