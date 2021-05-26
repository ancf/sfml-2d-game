#pragma once
#include "Define.h"
#include "States.h"

extern  sf::Font defaultFont;

class ScoresTable {
	sf::Text ScoreText[scoresSize];
	sf::RenderWindow * window;
	TopScoresIO * handleScores;
	sf::Text ScoresMessege;
public:
	states ScoresActivity(states current);
	ScoresTable(sf::RenderWindow * window, TopScoresIO * handleScores);
};