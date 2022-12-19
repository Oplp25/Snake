#include "entity.h"
#include <vector>
#include <iostream>
#include <random>
#include <string>
using namespace std;


fg::entity::entity(sf::Vector3f rgb, sf::Vector2f size, sf::Vector2f pos1, string type) {
		this->colour = sf::Color(rgb.x,rgb.y,rgb.z);
		this->hitbox = sf::RectangleShape(size);
		this->hitbox.setFillColor(this->colour);
		this->pos = pos1;
		this->size = size;
		this->direction = 1;
		this->type = type;
}

void fg::entity::draw(sf::RenderWindow &win) {
	this->hitbox.setPosition(this->pos);
	win.draw(this->hitbox);
}

void fg::entity::move() {
	switch (this->direction) {
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
	if (this->direction > 1) {
		if ((newD + 2) != direction) {
			this->direction = newD;
		}
	}
	else {
		if (newD-2 != this->direction) {
			this->direction = newD;
		}
	}
}

void fg::entity::setSnake() {
	this->vel = 0.03;
}

bool fg::entity::collidesWith(entity target) {


	bool width = max(this->pos.x, target.pos.x) < min(this->pos.x + this->size.x, target.pos.x + target.size.x);
	bool height = min(this->pos.y + this->size.y, target.pos.y + target.size.y) > max(this->pos.y, target.pos.y);
	return width && height;
}