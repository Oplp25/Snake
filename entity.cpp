#include "entity.h"
#include <vector>
#include <iostream>
using namespace std;


fg::entity::entity(sf::Vector3f rgb, sf::Vector2f size, sf::Vector2f pos) {
		colour = sf::Color(rgb.x,rgb.y,rgb.z);
		hitbox = sf::RectangleShape(size);
		hitbox.setFillColor(colour);
		this -> pos = pos;
}

void fg::entity::draw(sf::RenderWindow &win) {
	hitbox.setPosition(pos);
	win.draw(hitbox);
}

void fg::entity::move() {
	switch (direction) {
	case 0:pos.y += vel;
	case 1:pos.x -= vel;
	case 2:pos.y -= vel;
	case 3:pos.x += vel;
	}

}