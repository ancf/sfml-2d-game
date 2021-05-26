#pragma once
#include "SFML/Graphics.hpp"
#include "Define.h"


extern sf::Texture sprites;
extern  sf::Texture backgrounds;
extern sf::Texture animated_player;
extern  sf::Font defaultFont;

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &menu_window);
//	void draw_test(sf::RenderWindow &menu_window);
	void upwards();
	void downwards();
	void ChangeColorOnHover(int HoveredIndex);
	int GetPressedIndex() { return SelectedIndex; }
	sf::RectangleShape MenuButton[POSITIONS_NUMBER];
	
private:
	int SelectedIndex;
	int ButtonWidth;
	int ButtonHeight;


	
	sf::Text MenuText[POSITIONS_NUMBER];

};

