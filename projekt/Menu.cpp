#include "Menu.h"



Menu::Menu(float width, float height)
{
	this->ButtonWidth = MenuButtonWidth;
	this->ButtonHeight = MenuButtonHeight;

	double base_h = height / (POSITIONS_NUMBER + 1);
	
	MenuText[0].setString(MenuButton0);
	MenuText[1].setString(MenuButton1);
	MenuText[2].setString(MenuButton2);
	MenuText[3].setString(MenuButton3);
	MenuText[4].setString(MenuButton4);

	for (int i = 0;i < POSITIONS_NUMBER;i++) {
		MenuButton[i].setSize(sf::Vector2f(ButtonWidth, ButtonHeight));
		MenuButton[i].setFillColor(sf::Color::White);
		MenuButton[i].setPosition(sf::Vector2f(width / 2 - ButtonWidth / 2, base_h * (i+1)));

		MenuText[i].setFont(defaultFont);
		MenuText[i].setFillColor(sf::Color::Blue);
		MenuText[i].setPosition(sf::Vector2f(width / 2 - MenuText[i].getLocalBounds().width / 2, base_h * (i+1)));
	}


	

	this->SelectedIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0;i<POSITIONS_NUMBER;i++) {
		window.draw(MenuButton[i]);
		window.draw(MenuText[i]);
		
	}
}


void Menu::upwards() {
	if (SelectedIndex > 0) {
		MenuText[SelectedIndex].setFillColor(sf::Color::Black);
		SelectedIndex--;
		MenuText[SelectedIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::downwards() {
	if (SelectedIndex + 1 < POSITIONS_NUMBER) {
		MenuText[SelectedIndex].setFillColor(sf::Color::Black);
		SelectedIndex++;
		MenuText[SelectedIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::ChangeColorOnHover(int HoveredIndex) {
	
	if (HoveredIndex >= 0) {
		for (int i = 0;i < POSITIONS_NUMBER;i++) {
			if (i == HoveredIndex) {
				MenuText[i].setFillColor(sf::Color::Blue);
			}
			else {
				MenuText[i].setFillColor(sf::Color::Black);
			}

		}
		SelectedIndex = HoveredIndex;
	}
}