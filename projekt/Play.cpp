
#include "Play.h"


sf::RenderWindow * FallingObject::play_window;

double FallingObject::speed = FallSpeed;
double RangeBonus::RangeModifier = RangeMultiplier;
double SpeedBonus::SpeedModifier = SpeedMultiplier;




FallingObject::FallingObject(const sf::Texture &texture, const sf::IntRect &rectangle) : sprite(texture, rectangle) {
	
}

double FallingObject::getPosX() {
	return this->posX;
};
double FallingObject::getPosY() {
	return this->posY;
};
double FallingObject::getWidth() {
	return this->width;
};
double FallingObject::getHeight() {
	return this->height;
};

void FallingObject::setPosX(double posX_) {
	this->posX = posX_;
};
void  FallingObject::setPosY(double posY_) {
	this->posY = posY_;
};
void  FallingObject::setWidth(double width_) {
	this->width = width_;
};
void  FallingObject::setHeight(double height_) {
	this->height = height_;
};

CatchObject::CatchObject() : FallingObject(sprites, sf::IntRect(288, 360, 70, 70)) {

	this->setHeight(70);
	this->setWidth(70);


	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000 - this->getWidth() - 1);


	this->setPosY(0);
	std::cout << dist(rng) << std::endl;
	std::cout << (dist(rng) * this->play_window->getSize().x) / 1000 << std::endl;



	
		this->setPosX(dist(rng) * this->play_window->getSize().x / 1000);
		

		sprite.setPosition(sf::Vector2f(this->getPosX(), this->getPosY()));
		
}

void FallingObject::move(float steps) {
	this->posY = this->posY + steps;
	sprite.setPosition(sf::Vector2f(this->posX, this->posY));
}

void FallingObject::draw() {
	this->play_window->draw(this->sprite);
	
}


DangerousObject::DangerousObject() : FallingObject(sprites, sf::IntRect(87, 259, 40, 30)) {


	this->setHeight(40);
	this->setWidth(30);

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000 - this->getWidth() - 1);


	this->setPosY(0);
	std::cout << dist(rng) << std::endl;
	std::cout << (dist(rng) * this->play_window->getSize().x) / 1000 << std::endl;




	this->setPosX(dist(rng) * this->play_window->getSize().x / 1000);


	sprite.setPosition(sf::Vector2f(this->getPosX(), this->getPosY()));

}

EndurenceBonus::EndurenceBonus() : FallingObject(sprites, sf::IntRect(144, 362, 70, 70)) {
	

	this->setHeight(70);
	this->setWidth(70);

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000 - this->getWidth() - 1);


	this->setPosY(0);



	this->setPosX(dist(rng) * this->play_window->getSize().x / 1000);


	sprite.setPosition(sf::Vector2f(this->getPosX(), this->getPosY()));

}

SpeedBonus::SpeedBonus() : FallingObject(sprites, sf::IntRect(144, 218, 70, 70)) {
	

	this->setHeight(70);
	this->setWidth(70);

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000 - this->getWidth() - 1);


	this->setPosY(0);
	std::cout << dist(rng) << std::endl;
	std::cout << (dist(rng) * this->play_window->getSize().x) / 1000 << std::endl;




	this->setPosX(dist(rng) * this->play_window->getSize().x / 1000);

	sprite.setPosition(sf::Vector2f(this->getPosX(), this->getPosY()));

}

RangeBonus::RangeBonus() : FallingObject(sprites, sf::IntRect(131, 72, 70, 70)) {
	this->setHeight(70);
	this->setWidth(70);


	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000 - this->getWidth() - 1);


	this->setPosY(0);
	std::cout << dist(rng) << std::endl;
	std::cout << (dist(rng) * this->play_window->getSize().x) / 1000 << std::endl;




	this->setPosX(dist(rng) * this->play_window->getSize().x / 1000);


	sprite.setPosition(sf::Vector2f(this->getPosX(), this->getPosY()));
}


void Player::draw(){
	this->play_window->draw(this->sprite);
};
void Player::moveLeft(float steps){
	this->isFlipped = true; 
	this->sprite.setTextureRect(sf::IntRect(221 + width, 102, -width , height));
	
	if (this->hasBoostedSpeed) {
		this->posX -= this->baseSpeed * steps * SpeedBonus::SpeedModifier;
	}
	else {
		this->posX -= this->baseSpeed * steps;
	}
	if (this->posX < 0) this->posX = 0;

	this->sprite.setPosition(sf::Vector2f(this->posX, this->posY));
};
void Player::moveRight(float steps) {
	if(this->isFlipped)
		this->sprite.setTextureRect(sf::IntRect(221, 102, width , height));
		
	if (this->hasBoostedSpeed) {
		this->posX += this->baseSpeed * steps * SpeedBonus::SpeedModifier;
	}
	else {
		this->posX += this->baseSpeed * steps;
	}



	if (this->posX > (int)play_window->getSize().x) this->posX = play_window->getSize().x;
	
	this->sprite.setPosition(sf::Vector2f(this->posX, this->posY));

};
void Player::moveJump(float steps) {
	this->verticalSpeed -= this->gravity * steps;

	std::cout << this->verticalSpeed << std::endl;

	this->posY -= this->verticalSpeed * steps;

	std::cout << this->posY << std::endl;

	if (this->play_window->getSize().y - this->height < this->posY) {
		
		this->posY = play_window->getSize().y - this->height;
	} 

	if (this->posY == play_window->getSize().y - this->height) {
	//	std::cout << "Jump ended" << std::endl;
		this->isJumping = false;

	}
	
	this->sprite.setPosition(sf::Vector2f(this->posX, this->posY));
};

bool Player::checkCollision(FallingObject * other) {
	if (this->posX < other->getPosX() + other->getWidth() &&
		this->posX + this->width > other->getPosX() &&
		this->posY < other->getPosY() + other->getHeight() &&
		this->posY + this->height > other->getPosY()) {
		return true;
	}
	else {
		return false;
	}
};

Player::Player(sf::RenderWindow * play_window) : sprite(animated_player, sf::IntRect(221, 102, 69, 92)) {

	this->isJumping = false;
	this->score = 0;
	this->play_window = play_window;
	this->baseSpeed = PlayerSpeed;
	this->verticalSpeed = 0.0;
	this->gravity = PlayerGravity;
	this->width = 69;
	this->height = 92;
	this->posX = (this->play_window->getSize().x / 2) - (this->width / 2);
	this->posY = this->play_window->getSize().y - this->height;


	this->sprite.setPosition(sf::Vector2f(this->posX, this->posY));


};


bool Player::checkIfBoostedRange() {
	return this->hasBoostedRange;
};
bool Player::checkIfBoostedEndurence() {
	return this->hasBoostedEndurence;
};
bool Player::checkIfBoostedSpeed() {
	return this->hasBoostedSpeed;
};
bool Player::checkIfIsFlipped() {
	return this->isFlipped;
};
bool Player::checkIfIsJumping() {
	return this->isJumping;
};
double Player::getWidth() {
	return this->width;
};
double Player::getHeight() {
	return this->height;
};
double Player::getBaseSpeed() {
	return this->baseSpeed;
};
double Player::getVerticalSpeed() {
	return this->verticalSpeed;
};
double Player::getGravity() {
	return this->gravity;
};
double Player::getPosX() {
	return this->posX;
};
double Player::getPosY() {
	return this->posY;
};
int Player::getScore() {
	return this->score;
};


void Player::setBoostedRange(bool hasBoostedRange_) {
	this->hasBoostedRange = hasBoostedRange_;
};
void Player::setBoostedEndurence(bool hasBoostedEndurence_) {
	this->hasBoostedEndurence = hasBoostedEndurence_;
};
void Player::setBoostedSpeed(bool hasBoostedSpeed_) {
	this->hasBoostedSpeed = hasBoostedSpeed_;
};
void Player::setFlipped(bool isFlipped_) {
	this->isFlipped = isFlipped_;
};
void Player::setJumping(bool isJumping_) {
	this->isJumping = isJumping_;
};
void Player::setWidth(double width_) {
	this->width = width_;
};
void Player::setHeight(double height_) {
	this->height = height_;
};
void Player::setBaseSpeed(double baseSpeed_) {
	this->baseSpeed = baseSpeed_;
};
void Player::setVerticalSpeed(double verticalSpeed_) {
	this->verticalSpeed = verticalSpeed_;
};
void Player::setGravity(double gravity_) {
	this->gravity = gravity_;
};
void Player::setPosX(double posX_) {
	this->posX = posX_;
};
void Player::setPosY(double posY_) {
	this->posY = posY_;
};
void Player::setScore(int score_) {
	this->score = score_;
};


Play::Play(sf::RenderWindow * window, TopScoresIO * handleScores){

	this->window = window;
	this->handleScores = handleScores;
	this->ourPlayer = new Player(this->window);

}

states Play::GameOver(states current) {


	
	

	this->handleScores->input();


//	sf::Font hudFont;

//	hudFont.loadFromFile("times.ttf");

	

	sf::Text GameOver;
	sf::RectangleShape NameInputField;
	sf::String NameInput;
	sf::Text NameText;

	GameOver.setFont(defaultFont);
	GameOver.setCharacterSize(FontBig);
	GameOver.setFillColor(sf::Color::White);
	
	GameOver.setString("Player died \nScore: " + intToStr(this->ourPlayer->getScore()) + "\nType player name\nconsisting of maximum 12 letters and numbers\nand press SPACE");
	GameOver.setPosition(this->window->getSize().x / 2 - GameOver.getLocalBounds().width / 2, this->window->getSize().y / 4 - GameOver.getLocalBounds().height / 2);
	
	NameInputField.setFillColor(sf::Color::White);
	NameInputField.setSize(sf::Vector2f(this->window->getSize().x / 3, this->window->getSize().y / 12));
	NameInputField.setPosition(this->window->getSize().x / 2 - NameInputField.getLocalBounds().width / 2, this->window->getSize().y / 2 - NameInputField.getLocalBounds().height / 2);
	

	NameText.setFont(defaultFont);
	NameText.setCharacterSize(FontHuge);
	NameText.setFillColor(sf::Color::Black);
	NameText.setPosition(this->window->getSize().x / 2 - NameInputField.getLocalBounds().width / 2  + 5, this->window->getSize().y / 2 - NameInputField.getLocalBounds().height / 2);

	
	
//	this->window->display();
	sf::Event event;
	while (this->window->isOpen()) {
		
		while (this->window->pollEvent(event))
		{

			if (event.type == sf::Event::TextEntered)
			{
				if(event.text.unicode != '\b') {
					std::string tmp;
					if (event.text.unicode < 128) {
						tmp += static_cast<char>(event.text.unicode);

						if (std::regex_match(tmp, std::regex("[0-9]|[A-Z]|[a-z]")) && NameInput.getSize() < 12) {
							NameInput += event.text.unicode;
							NameText.setString(NameInput);
						}
					}
				}
				else {
					if (NameInput.getSize() > 0) {
						NameInput.erase(NameInput.getSize() - 1, 1);
						NameText.setString(NameInput);
					}
				}
				
				

			}

			if (event.type == sf::Event::KeyPressed)
			{


	
				if (event.key.code == sf::Keyboard::Space)
				{
					
					Score newScore(toGenericString(NameInput), this->ourPlayer->getScore());

					this->handleScores->add(newScore);
					this->handleScores->output(); 

					current = MenuState;
					return current;
				}
			}
			
		}
	//	std::cout << "sth" << std::endl;

		this->window->clear(sf::Color::Black);
		this->window->draw(GameOver);
		this->window->draw(NameInputField);
		this->window->draw(NameText);
		this->window->display();
		
	}
}

Player::~Player() {
//	delete this->play_window;
}

Play::~Play() {
	delete this->ourPlayer;
}

states Play::PlayActivity(states current) {

	double height = this->window->getSize().y;

	sf::Sprite background(backgrounds);

	

	sf::Text hudScore;
	sf::Text hudSpeed;
	sf::Text hudEndurence;
	sf::Text hudRange;
/*
	sf::Text GameOver;

	GameOver.setFont(defaultFont);
	GameOver.setCharacterSize(FontBig);
	GameOver.setFillColor(sf::Color::White);
	GameOver.setPosition(640 - GameOver.getLocalBounds().width / 2, 320 - GameOver.getLocalBounds().height/2);
*/

	sf::Sprite hudIconSpeed(sprites, sf::IntRect(144, 218, 70, 70));
	sf::Sprite hudIconEndurence(sprites, sf::IntRect(144, 362, 70, 70));
	sf::Sprite hudIconRange(sprites, sf::IntRect(131, 72, 70, 70));

	hudIconSpeed.setPosition(640, 1);
	hudIconRange.setPosition(770, 1);
	hudIconEndurence.setPosition(900, 1);



	hudScore.setFont(defaultFont);
	hudScore.setCharacterSize(FontNormal);
	hudScore.setFillColor(sf::Color::White);
	hudScore.setPosition(5, 16);

	hudSpeed.setFont(defaultFont);
	hudSpeed.setCharacterSize(FontNormal);
	hudSpeed.setFillColor(sf::Color::White);
	hudSpeed.setPosition(640, 51);

	hudRange.setFont(defaultFont);
	hudRange.setCharacterSize(FontNormal);
	hudRange.setFillColor(sf::Color::White);
	hudRange.setPosition(770, 51);

	hudEndurence.setFont(defaultFont);
	hudEndurence.setCharacterSize(FontNormal);
	hudEndurence.setFillColor(sf::Color::White);
	hudEndurence.setPosition(900, 51);

	background.setPosition(0, 128);



	int CatchDensity = CatchBreakpoint;
	int DangerDensity = DangerBreakpoint;
	int SpeedDensity = SpeedBreakpoint;
	int EndurenceDensity = EndurenceBreakpoint;
	int RangeDensity = RangeBreakpoint;

	

	sf::Time elapsed_time;
	sf::Time elapsed_small;
	sf::Clock r;
	sf::Clock rsmall;


	sf::Time delta_time = sf::milliseconds(2000);
	sf::Time delta_small = sf::milliseconds(33); // oko³o 60 FPS

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000);

	

	sf::Color greenish(0x7ab71eff);
	
	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	sf::Clock endurenceClock;
	sf::Clock speedClock;
	sf::Clock rangeClock;

	sf::Clock playerClock;

	sf::Time endurenceTime;
	sf::Time speedTime;
	sf::Time rangeTime;

	sf::Time playerTime;

	while (this->window->isOpen()) {

		sf::Event event;

		while (this->window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				current = MenuState;
				return current;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{

				case sf::Keyboard::Up:     upFlag = true; break;
				case sf::Keyboard::Down:    downFlag = true; break;
				case sf::Keyboard::Left:    leftFlag = true; break;
				case sf::Keyboard::Right:   rightFlag = true; break;
				default: break;
				}
			}


			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{

				case sf::Keyboard::Up:     upFlag = false; break;
				case sf::Keyboard::Down:    downFlag = false; break;
				case sf::Keyboard::Left:    leftFlag = false; break;
				case sf::Keyboard::Right:   rightFlag = false; break;
				default: break;
				}
			}
		}

		playerTime = playerClock.getElapsedTime();
		playerClock.restart();

		if (leftFlag)
			this->ourPlayer->moveLeft(playerTime.asSeconds());
		if (rightFlag)
			this->ourPlayer->moveRight(playerTime.asSeconds());
		if (upFlag && this->ourPlayer->checkIfIsJumping() == false) {
			this->ourPlayer->setJumping(true);
			if (this->ourPlayer->checkIfBoostedRange() == true) {
				this->ourPlayer->setVerticalSpeed(PlayerJumpSpeed * RangeBonus::RangeModifier);
			}
			else {
				this->ourPlayer->setVerticalSpeed(PlayerJumpSpeed);
			}

		}
		if (downFlag);

		if (this->ourPlayer->checkIfIsJumping()) {
			this->ourPlayer->moveJump(playerTime.asSeconds());
		}

		if (ourPlayer->checkIfBoostedEndurence() == true) {
			
			endurenceTime = endurenceClock.getElapsedTime();
			
			if (endurenceTime.asSeconds() > 30) {
				ourPlayer->setBoostedEndurence(false);
				
			}
		}

		if (ourPlayer->checkIfBoostedSpeed() == true) {
			
			speedTime = speedClock.getElapsedTime();
			
			if (speedTime.asSeconds() > 30) {
				ourPlayer->setBoostedSpeed(false);
				
			}
		}

		if (ourPlayer->checkIfBoostedRange() == true) {
			
			rangeTime = rangeClock.getElapsedTime();
			
			if (rangeTime.asSeconds() > 30) {
				ourPlayer->setBoostedRange(false);
				
			}
		}

	



		elapsed_time += r.restart();
		elapsed_small += rsmall.restart();

		if (elapsed_time >= delta_time) {

			if (dist(rng) <= CatchDensity) {
				this->CatchArray.push_back(CatchObject());

			}
			else if (dist(rng) > CatchDensity && dist(rng) <= DangerDensity) {
				this->DangerArray.push_back(DangerousObject());

			}
			else if (dist(rng) > DangerDensity && dist(rng) <= SpeedDensity) {
				this->SpeedArray.push_back(SpeedBonus());

			}
			else if (dist(rng) > SpeedDensity && dist(rng) <= EndurenceDensity) {
				this->EndurenceArray.push_back(EndurenceBonus());

			}
			else if (dist(rng) > EndurenceDensity && dist(rng) <= RangeDensity) {
				this->RangeArray.push_back(RangeBonus());

			}


			elapsed_time -= delta_time;
		}

		if (elapsed_small >= delta_small) {


			for (int i = 0;i < CatchArray.size();i++) {
				this->CatchArray[i].move(CatchArray[i].speed);
				if (this->CatchArray[i].getPosY() > height) {
					this->CatchArray.erase(CatchArray.begin() + i);
					
				}
				else if (ourPlayer->checkCollision(&CatchArray[i])) {
					int tmp = ourPlayer->getScore();
					tmp++;
					ourPlayer->setScore(tmp);
					this->CatchArray.erase(CatchArray.begin() + i);
					
				}
			}

			for (int i = 0;i < DangerArray.size();i++) {
				this->DangerArray[i].move(DangerArray[i].speed);
				if (this->DangerArray[i].getPosY() > height) {
					this->DangerArray.erase(DangerArray.begin() + i);
					
				}
				else if (ourPlayer->checkCollision(&DangerArray[i])) {
				
					this->DangerArray.erase(DangerArray.begin() + i);
					if (!ourPlayer->checkIfBoostedEndurence()) {
						this->window->clear(sf::Color::Black);
						this->window->display();
						current = PlayState;
						return current;
						
					}

				}
			}



			for (int i = 0;i < SpeedArray.size();i++) {
				this->SpeedArray[i].move(SpeedArray[i].speed);
				if (this->SpeedArray[i].getPosY() > height) {
					this->SpeedArray.erase(SpeedArray.begin() + i);
					
				}
				else if (ourPlayer->checkCollision(&SpeedArray[i])) {
					ourPlayer->setBoostedSpeed(true);
					this->SpeedArray.erase(SpeedArray.begin() + i);
					
					speedClock.restart();
				}
			}

			for (int i = 0;i < EndurenceArray.size();i++) {
				this->EndurenceArray[i].move(EndurenceArray[i].speed);
				if (this->EndurenceArray[i].getPosY() > height) {
					this->EndurenceArray.erase(EndurenceArray.begin() + i);
					
				}
				else if (ourPlayer->checkCollision(&EndurenceArray[i])) {
					ourPlayer->setBoostedEndurence(true);
					this->EndurenceArray.erase(EndurenceArray.begin() + i);
					
					endurenceClock.restart();
				}
			}

			for (int i = 0;i < RangeArray.size();i++) {
				this->RangeArray[i].move(RangeArray[i].speed);
				if (this->RangeArray[i].getPosY() > height) {
					this->RangeArray.erase(RangeArray.begin() + i);
				
				}
				else if (ourPlayer->checkCollision(&RangeArray[i])) {
					ourPlayer->setBoostedRange(true);
					this->RangeArray.erase(RangeArray.begin() + i);
					
					rangeClock.restart();
				}
			}

		
			
	

		
			


			hudScore.setString(hudStringScore + intToStr(ourPlayer->getScore()));
			if (this->ourPlayer->checkIfBoostedSpeed())
				hudSpeed.setString(hudSpeedActive + intToStr(30 - speedTime.asSeconds()) + "s");
			else
				hudSpeed.setString(hudSpeedInactive);
			if (this->ourPlayer->checkIfBoostedEndurence())
				hudEndurence.setString(hudEndurenceActive + intToStr(30 - endurenceTime.asSeconds()) + "s");
			else
				hudEndurence.setString(hudEndurenceInactive);
			if (this->ourPlayer->checkIfBoostedRange())
				hudRange.setString(hudRangeActive + intToStr(30 - rangeTime.asSeconds()) + "s");
			else
				hudRange.setString(hudRangeInactive);


			this->window->clear(greenish);
			this->window->draw(background);

			for (int i = 0;i < CatchArray.size();i++) {

				this->CatchArray[i].draw();
			}

			for (int i = 0;i < DangerArray.size();i++) {

				this->DangerArray[i].draw();
			}


			for (int i = 0;i < SpeedArray.size();i++) {

				this->SpeedArray[i].draw();
			}


			for (int i = 0;i < EndurenceArray.size();i++) {

				this->EndurenceArray[i].draw();
			}


			for (int i = 0;i < RangeArray.size();i++) {

				this->RangeArray[i].draw();
			}

			this->ourPlayer->draw();
			this->window->draw(hudScore);
			this->window->draw(hudIconSpeed);
			this->window->draw(hudIconEndurence);
			this->window->draw(hudIconRange);
			this->window->draw(hudSpeed);
			this->window->draw(hudEndurence);
			this->window->draw(hudRange);

			this->window->display();

			elapsed_small -= delta_small;
		}

		

		

	}


	current = MenuState;
	return current;
}

states SwitchStateIndex(int StateIndex, states current, sf::RenderWindow &window, TopScoresIO &handleScores) {
	
	if (StateIndex == 0) {
		current = PlayState;
		Play playOpen(&window, &handleScores);
		current = playOpen.PlayActivity(current);
		
		if(current == PlayState)
			current = playOpen.GameOver(current);

	//	playOpen.ourPlayer->~Player();
	//	playOpen.~Play();

		return current;
	} else if (StateIndex == 1) {
		current = ScoresState;
	
		ScoresTable currentTable(&window, &handleScores);
		current = currentTable.ScoresActivity(current);
		return current;
	}
	else if (StateIndex == 2) {
		current = OptionsState;

		current = options(current);
		return current;
	}
	else if (StateIndex == 3) {
		current = AboutState;

		current = about(current);
		return current;
	}
	else if (StateIndex == 4) {
		window.close();
	}
	else {
		return current;
	}
	
}



