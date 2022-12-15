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
		void draw(sf::RenderWindow& win);
		void move();
		bool collidesWith(entity target);

		sf::Vector2f pos;
		sf::RectangleShape hitbox;
		int direction;//0=down, 1=left, 2=up, 3=right
		int  vel;//velocity

		entity(sf::Vector3f rgb, sf::Vector2f pos, sf::Vector2f size);

		entity() {}
	};
}

#endif // ! SNAKE
