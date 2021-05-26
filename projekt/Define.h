#pragma once
#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <sstream> 
#include <string>
#include <fstream>
#include <algorithm> 
#include <exception>

#define filenameScores "topscores.txt"
#define scoresSize 10
#define POSITIONS_NUMBER 5
#define ScoresString "Top scores\nPress SPACE to go back to menu"

#define MenuButton0 "Play"
#define MenuButton1 "Top Scores"
#define MenuButton2 "Preferences"
#define MenuButton3 "About"
#define MenuButton4 "Exit"
#define MenuButtonWidth 300
#define MenuButtonHeight 50

#define hudStringScore "Score \n"
#define hudSpeedActive "Speed bonus \n"
#define hudSpeedInactive "Speed bonus \nInactive"
#define hudEndurenceActive "Endurence bonus \n"
#define hudEndurenceInactive "Endurence bonus \nInactive"
#define hudRangeActive "Range bonus \n"
#define hudRangeInactive "Range bonus \nInactive"

#define FallSpeed 10.00
#define RangeMultiplier 1.25
#define SpeedMultiplier 1.75

#define PlayerSpeed 150.0
#define PlayerGravity 300.0
#define PlayerJumpSpeed 300.0


#define FontNormal 16
#define FontBig 32
#define FontHuge 40

#define CatchBreakpoint 500;
#define DangerBreakpoint 850;
#define SpeedBreakpoint 900;
#define EndurenceBreakpoint 950;
#define RangeBreakpoint 1000;



std::string intToStr(int x);
std::string toGenericString(sf::String str);




bool LoadResources();

class Score {

	std::string name;
	int points;
public:
	Score(std::string name_, int points_);
	std::string getName();
	int getPoints();
};


class TopScoresIO {
	int maxSize;
	std::vector<Score> scores;
	std::string filename;
public:
	void input();
	void output();
	void add(Score scoreToAdd);
	Score getNth(int i);
	TopScoresIO(std::string filename_, int max_size);
};
