#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
#include <iostream>
#include <SFML/Graphics.hpp>



#include "Mouse.h"
#include "Play.h"



int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (!LoadResources()) {
		system("PAUSE");
		return -1;
	}
	

	sf::RenderWindow window(sf::VideoMode(1024, 640), "My game");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);

	FallingObject::play_window = &window;


	Menu menu(window.getSize().x, window.getSize().y);

	

	MyMouse MenuMouse(window);

	TopScoresIO handleScores(filenameScores, scoresSize);

	handleScores.input();

	while (window.isOpen())
	{
		sf::Event event;


		states current = MenuState;

		while (window.pollEvent(event) && current==MenuState) {
			menu.ChangeColorOnHover(MenuMouse.CheckMenuPosition(menu.MenuButton,POSITIONS_NUMBER));
			
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed: 
				switch (event.mouseButton.button) {
					case sf::Mouse::Left:
						current = SwitchStateIndex(MenuMouse.CheckMenuPosition(menu.MenuButton, POSITIONS_NUMBER), current, window, handleScores);
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.upwards();
					break;
				case sf::Keyboard::Down:
					menu.downwards();
					break;
				case sf::Keyboard::Return:
					current = SwitchStateIndex(menu.GetPressedIndex(), current, window, handleScores);
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();

				break;


			}

			

			window.clear();
			menu.draw(window);
			window.display();
		}

	}

	return 0;
}