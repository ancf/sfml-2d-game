#pragma once
#include "SFML/Graphics.hpp"

#include "States.h"
#include "Scores.h"
#include "Menu.h"
#include <iostream>
#include <random>
#include <vector>
#include <sstream> 
#include <string>
#include <regex>
#include <fstream>
#include <algorithm> 

extern sf::Texture sprites;
extern  sf::Texture backgrounds;
extern sf::Texture animated_player;
extern  sf::Font defaultFont;

class FallingObject {
	
private:	
	double posX;
	double posY;
	double width;
	double height;
public: 
	static double speed;
	static sf::RenderWindow * play_window;
	virtual void move(float steps);
	virtual void draw();

	double getPosX();
	double getPosY();
	double getWidth();
	double getHeight();

	void  setPosX(double posX_);
	void  setPosY(double posY_);
	void  setWidth(double width_);
	void  setHeight(double height_);

	sf::Sprite sprite;

	FallingObject(const sf::Texture &texture, const sf::IntRect &rectangle);
};

class CatchObject : public FallingObject {

public:

	 CatchObject();
	
};

class DangerousObject : public FallingObject {

public:

	DangerousObject();
};

class EndurenceBonus : public FallingObject {
public:

	EndurenceBonus();
};

class SpeedBonus : public FallingObject {
public:
	static double SpeedModifier;

	SpeedBonus();
};

class RangeBonus : public FallingObject {
public:
	static double RangeModifier;

	RangeBonus();
};

class Player {
 private:
	bool hasBoostedRange;
	bool hasBoostedEndurence;
	bool hasBoostedSpeed;
	bool isFlipped;
	bool isJumping;
	double width;
	double height;
	double baseSpeed;
	double verticalSpeed;
	double gravity;
	double posX;
	double posY;
	int score;
public:
	
	sf::RenderWindow * play_window;

	sf::Sprite sprite;

	void draw();
	void moveLeft(float steps);
	void moveRight(float steps);
	void moveJump(float steps);

	Player(sf::RenderWindow * play_window);
	~Player();
	bool checkCollision(FallingObject * other);


	bool checkIfBoostedRange();
	bool checkIfBoostedEndurence();
	bool checkIfBoostedSpeed();
	bool checkIfIsFlipped();
	bool checkIfIsJumping();
	double getWidth();
	double getHeight();
	double getBaseSpeed();
	double getVerticalSpeed();
	double getGravity();
	double getPosX();
	double getPosY();
	int getScore();

	void setBoostedRange(bool hasBoostedRange_);
	void setBoostedEndurence(bool hasBoostedEndurence_);
	void setBoostedSpeed(bool hasBoostedSpeed_);
	void setFlipped(bool isFlipped_);
	void setJumping(bool isJumping_);
	void setWidth(double width_);
	void setHeight(double height_);
	void setBaseSpeed(double baseSpeed_);
	void setVerticalSpeed(double verticalSpeed_);
	void setGravity(double gravity_);
	void setPosX(double posX_);
	void setPosY(double posY_);
	void setScore(int score_);


};


class Play {
private:
	TopScoresIO * handleScores;
	sf::RenderWindow * window;
public:
	Play(sf::RenderWindow * window, TopScoresIO * handleScores);
	std::vector<CatchObject> CatchArray;
	std::vector<DangerousObject> DangerArray;
	std::vector<EndurenceBonus> EndurenceArray;
	std::vector<SpeedBonus> SpeedArray;
	std::vector<RangeBonus> RangeArray;
	Player * ourPlayer;

	
	states PlayActivity(states current);
	states GameOver(states current);

	~Play();
//	void draw();
	



};

states SwitchStateIndex(int StateIndex, states current, sf::RenderWindow &window, TopScoresIO &handleScores);