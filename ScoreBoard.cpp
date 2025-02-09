#include "ScoreBoard.h"



ScoreBoard::ScoreBoard()
{
}

void ScoreBoard::uploadScoreBoard()
{
	ofstream file;
	file.open("scores.txt");
	for (auto it = mScores.cbegin(); it != mScores.cend(); ++it)
	{
		file << it->first << "," << it->second << endl;
	}
	file.close();
}

void ScoreBoard::getScores()
{
	ifstream file;
	string line, temp, data;
	file.open("scores.txt");
	string values [2];
	int i = 0;
	while (getline(file, line)) {
		stringstream ss(line);
		while (getline(ss, temp, ','))
		{
			if (i % 2 == 0)
				values[0] = temp;
			else
				values[1] = temp;
			i++;
		}
		if (i % 2 == 0)
			mScores.insert(pair<string, int>(values[0], stoi(values[1])));
		


	}
}

string ScoreBoard::displayScoreBoard()
{
	ifstream file;
	string line;
	string toReturn = "";
	file.open("scores.txt");
	if (!file.is_open())
	{
		return "File Not Found!!";
	}

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
