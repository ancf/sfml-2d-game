#pragma once
#include <SFML/Graphics.hpp>


class MyMouse {
public:
	MyMouse(const sf::RenderWindow &window_);
	~MyMouse();

	int CheckMenuPosition(sf::RectangleShape box[], int numberOfPositions);
private:
	const sf::RenderWindow& window;
};
