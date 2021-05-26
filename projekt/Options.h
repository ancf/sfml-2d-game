#pragma once
#include "SFML/Graphics.hpp"



class Options
{
public:
	Options(float width, float height);
	~Options();

	enum DifficultyLevel { Easy, Medium, Hard };
	int SelectedVolume;
	std::string SelectedName;
	

//	void draw(sf::RenderWindow &menu_window);
//	void draw_test(sf::RenderWindow &menu_window);
//	void upwards();
//	void downwards();
//	int GetPressedIndex() { return SelectedIndex; }

private:
	
//	int ButtonWidth = 300;
//	int ButtonHeight = 50;


//	sf::Font def;
//	sf::Text MenuText[POSITIONS_NUMBER];
//	sf::RectangleShape MenuButton[POSITIONS_NUMBER];
};

