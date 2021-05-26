
#include <iostream>
#include "States.h"




/*
states play(sf::RenderWindow &window, states current, Play play) {
	 
	window.clear();
	play.draw(window);
	window.display();
	std::cout << "Play button pressed" << std::endl;
	system("PAUSE");
	current = MenuState;
	return current;
} */
states options(states current) {
	std::cout << "Preferences button pressed" << std::endl;
	current = MenuState;
	return current;
}
states about(states current) {
	std::cout << "About button pressed" << std::endl;
	current = MenuState;
	return current;
}/*
states scores(states current) {
	std::cout << "Top scores button pressed" << std::endl;
	current = MenuState;
	return current;
} */
/*
states exit(states current) {
	std::cout << "Exit button pressed" << std::endl;
//	window.close();

	current = MenuState;
	return current;
} */

