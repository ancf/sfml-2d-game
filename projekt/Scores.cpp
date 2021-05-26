#include "Scores.h"


states ScoresTable::ScoresActivity(states current) {
	sf::Event event;
	while (this->window->isOpen()) {

		while (this->window->pollEvent(event))
		{

		

			if (event.type == sf::Event::KeyPressed)
			{


				if (event.key.code == sf::Keyboard::Space)
				{
				
					current = MenuState;
					return current;
				}
			}
			else if (event.type == sf::Event::Closed) {
				current = MenuState;
				return current;
			}
				


		}
		this->window->clear(sf::Color::Black);
		this->window->draw(this->ScoresMessege);
		for (int i = 0;i < scoresSize;i++) {
			this->window->draw(this->ScoreText[i]);
		}
		this->window->display();

	}

	
};
ScoresTable::ScoresTable(sf::RenderWindow * window, TopScoresIO * handleScores) {
	this->window = window;
	this->handleScores = handleScores;

	double width = this->window->getSize().x;

	this->ScoresMessege.setFont(defaultFont);
	this->ScoresMessege.setFillColor(sf::Color::White);
	this->ScoresMessege.setString(ScoresString);
	this->ScoresMessege.setPosition(sf::Vector2f(width / 2 - this->ScoresMessege.getLocalBounds().width / 2, 10));

	double messegeHeight = 25 + this->ScoresMessege.getLocalBounds().height;
	double height = this->window->getSize().y - messegeHeight;
	
	double base_h = height / (scoresSize + 1);

	this->handleScores->input();

	for (int i = 0;i < scoresSize;i++) {
		this->ScoreText[i].setFont(defaultFont);
		this->ScoreText[i].setFillColor(sf::Color::White);
		Score tmpScore = this->handleScores->getNth(i);
		std::string tmp = toGenericString(tmpScore.getName()) +" "+ intToStr(tmpScore.getPoints());
		this->ScoreText[i].setString(tmp);
		this->ScoreText[i].setPosition(sf::Vector2f(width / 2 - ScoreText[i].getLocalBounds().width / 2, messegeHeight + base_h * i));
	}


	
};