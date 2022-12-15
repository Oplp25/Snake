#pragma once
#ifndef SNAKE
#define SNAKE
#include <SFML\Graphics.hpp>
#include <vector>
#include <String>


namespace fg {
	class entity {
	private:
		sf::Color colour;
	public:
		void setColour(int red, int blue, int green) {}
		void draw(sf::RenderWindow &win) {}
		sf::Vector2f move() {}
		bool collidesWith(entity target) {}

		sf::Vector2f pos;
		sf::RectangleShape hitbox;
		int direction;//0=down, 1=left, 2=up, 3=right
		int  vel;//velocity

		entity(sf::Vector3i rgb, sf::Vector2f pos, sf::Vector2f size) {}

		entity() {}
	};
}

#endif // ! SNAKE
