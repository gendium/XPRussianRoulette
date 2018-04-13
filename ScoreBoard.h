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
	map<string, double> mScores;
	ScoreBoard();
	bool uploadScoreBoard();
	void getScores();
	void displayScoreBoard();
	~ScoreBoard();
};

