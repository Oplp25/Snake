#include "entity.h"
#include <vector>
#include<iostream>
using namespace std;
void fg::entity::setColour(int red, int blue, int green) {
	if (0 <= red < 256 && 0 <= blue < 256 && 0 <= red < 256) {
		colour = sf::Color(red, blue, green);
	}
	else {
		cout << "Invalid size integer for rgb colour" << endl;
	}
}


fg::entity::entity(sf::Vector3i rgb, sf::Vector2f size, sf::Vector2f pos) {
		setColour(rgb.x,rgb.y,rgb.z);
		hitbox = sf::RectangleShape(size);
		hitbox.setFillColor(colour);
		pos = pos;
}

void fg::entity::draw(sf::RenderWindow &win) {
	hitbox.setPosition(pos);
	win.draw(hitbox);
}

sf::Vector2f fg::entity::move() {
	switch (direction){
	case 0:pos.y += vel;
	case 1:pos.x -= vel;
	case 2:pos.y -= vel;
	case 3:pos.x += vel;
	}

}