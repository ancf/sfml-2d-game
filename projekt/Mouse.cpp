#pragma once
#include "Mouse.h"



MyMouse::MyMouse(const sf::RenderWindow& window_) :
	window(window_) {};

MyMouse::~MyMouse() {
};

int MyMouse::CheckMenuPosition(sf::RectangleShape box[], int numberOfPositions) {
	for (int i = 0;i <  numberOfPositions;i++) {
		if (sf::Mouse::getPosition(window).x >= box[i].getPosition().x
			&& sf::Mouse::getPosition(window).x <= box[i].getPosition().x + box[i].getSize().x
			&& sf::Mouse::getPosition(window).y >= box[i].getPosition().y
			&& sf::Mouse::getPosition(window).y <= box[i].getPosition().y + box[i].getSize().y) {
			return i;
		}
	}
	
		return -1;
	
}