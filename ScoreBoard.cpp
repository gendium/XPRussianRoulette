#include "ScoreBoard.h"



ScoreBoard::ScoreBoard()
{
	mScores = new map<string, double>();
}

bool ScoreBoard::uploadScoreBoard()
{

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

void ScoreBoard::displayScoreBoard()
{
	ifstream file;
	string line;
	file.open("scores.txt");
	while (getline(file, line))
	{
		cout << line << "\n";
	}
	file.close();
}
ScoreBoard::~ScoreBoard()
{
}
