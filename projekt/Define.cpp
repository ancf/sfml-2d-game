
#include "Define.h"

sf::Texture sprites;
sf::Texture backgrounds;
sf::Texture animated_player;
sf::Font defaultFont;

class playerException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Failed to load p1_spritesheet.png";
	}
} plExc;

class itemsException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Failed to load items_spritesheet.png";
	}
} itExc;

class backgroundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Failed to load bg_shroom.png";
	}
} bgExc;

class fontException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Failed to load times.ttf";
	}
} fontExc;

bool LoadResources() {
	try {
		if (!animated_player.loadFromFile("p1_spritesheet.png")) {
			throw plExc;
		};
		if (!sprites.loadFromFile("items_spritesheet.png")) {
			throw itExc;
		};
		if (!backgrounds.loadFromFile("bg_shroom.png")) {
			throw bgExc;
		};
		if (!defaultFont.loadFromFile("times.ttf")) {
			throw fontExc;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
std::string toGenericString(sf::String str) {
	std::string tmp;
	for (int i = 0;i < str.getSize();i++) {
		tmp += static_cast<char>(str[i]);
	}

	return tmp;
}

std::string intToStr(int x)
{
	std::stringstream converted;
	converted << x;
	return converted.str();
}

Score::Score(std::string name_, int points_) {
	this->name = name_;
	this->points = points_;
}

std::string Score::getName() {

	return this->name;
}
;
int Score::getPoints() {
	return this->points;
};

TopScoresIO::TopScoresIO(std::string filename_, int maxSize_) {
	this->filename = filename_;
	this->maxSize = maxSize_;
}

void TopScoresIO::add(Score scoreToAdd) {

	this->scores.push_back(scoreToAdd);

	for (int i = 0;i < scores.size();i++) {
		std::cout << scores[i].getName() << " " << scores[i].getPoints() << std::endl;
	}


	std::sort(this->scores.begin(), this->scores.end(),
		[](Score & a, Score & b) -> bool {
		return a.getPoints() > b.getPoints();});


	for (int i = 0;i < scores.size();i++) {
		std::cout << scores[i].getName() << " " << scores[i].getPoints() << std::endl;
	}

	if (this->scores.size() >= this->maxSize) {


		this->scores.pop_back();
	}



	for (int i = 0;i < scores.size();i++) {
		std::cout << scores[i].getName() << " " << scores[i].getPoints() << std::endl;
	}
}

void TopScoresIO::input() {
	this->scores.erase(this->scores.begin(), this->scores.end());
	std::ifstream file;
	file.open(this->filename);
	std::string name;
	int points;
	while (!file.eof()) {
		file >> name >> points;
		this->scores.push_back(Score(name, points));
	}

}

void TopScoresIO::output() {
	std::ofstream file;
	file.open(this->filename, std::ofstream::out | std::ofstream::trunc);

	for (int i = 0;i < this->scores.size();i++) {
		if (i < this->scores.size() - 1) {
			file << this->scores[i].getName() << " " << this->scores[i].getPoints() << "\n";
		}
		else {
			file << this->scores[i].getName() << " " << this->scores[i].getPoints();

		}
	}

}

Score TopScoresIO::getNth(int i) {

	return this->scores[i];

};