#include "entity.h"
#include <vector>
#include <iostream>
using namespace std;


fg::entity::entity(sf::Vector3f rgb, sf::Vector2f size, sf::Vector2f pos1) {
		this->colour = sf::Color(rgb.x,rgb.y,rgb.z);
		this->hitbox = sf::RectangleShape(size);
		this->hitbox.setFillColor(this->colour);
		this->pos = pos1;
		this->direction = 1;
}

void fg::entity::draw(sf::RenderWindow &win) {
	this->hitbox.setPosition(this->pos);
	win.draw(this->hitbox);
}

void fg::entity::move() {
	cout << direction << endl;
	switch (direction) {
	default:
		break;
	case 0:
		this ->pos.y += this-> vel;
		break;
	case 1:
		this -> pos.x -= this->vel;
		break;
	case 2:
		this -> pos.y -= this->vel;
		break;
	case 3:
		this->pos.x += this->vel;
		break;
	}
}
void fg::entity::setDirection(int newD) {
	this->direction = newD;
	/*if (this->direction > 1) {
		if ((newD + 2) != direction) {
			this->direction = newD;
		}
	}
	else {
		if (newD-2 != this->direction) {
			this->direction = newD;
		}
	}*/
}

void fg::entity::setSnake() {
	this->vel = 0.05;
}