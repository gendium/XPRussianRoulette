#include "ScoreBoard.h"



ScoreBoard::ScoreBoard()
{
	//mScores = new map<string, double>();
}

bool ScoreBoard::uploadScoreBoard()
{
	return false;
}

void ScoreBoard::getScores()
{
	ifstream file;
	string line;
	file.open("scores.txt");
	while (getline(file, line)) {
		stringstream ss(line);

	}
}

string ScoreBoard::displayScoreBoard()
{
	ifstream file;
	string line;
	string toReturn = "";
	file.open("scores.txt");
	while (getline(file, line))
	{
		toReturn += line + "\n";
	}
	file.close();
	return toReturn;
}
ScoreBoard::~ScoreBoard()
{
}
