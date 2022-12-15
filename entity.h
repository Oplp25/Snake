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
		bool collidesWith(entity target);
		void move();

		int vel;//velocity
		int direction;//down:0 left:1 up:2 right:3
		sf::Vector2f pos;
		sf::RectangleShape hitbox;
		entity(sf::Vector3f rgb, sf::Vector2f pos, sf::Vector2f size);

		entity() {}
	};
}

#endif // ! SNAKE
