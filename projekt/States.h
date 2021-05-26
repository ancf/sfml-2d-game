#pragma once
#include <SFML/Graphics.hpp>






enum states {
	MenuState, PlayState, OptionsState, AboutState, ScoresState
};



states play(sf::RenderWindow &window, states current);
states options(states current);
states about(states current);
// states scores(states current);
// states exit(states current);

// states SwitchStateIndex(int StateIndex, states current, sf::RenderWindow &window, Menu menu);