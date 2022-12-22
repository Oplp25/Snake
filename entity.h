#pragma once
#ifndef SNAKE
#define SNAKE
#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include <random>


namespace fg {
	class entity {
	public:
		void draw(sf::RenderWindow& win);
		bool collidesWith(entity target);
		void move();
		void setDirection(int newD);
		void setSnake();

		std::string type;
		float vel;//velocity
		int direction;//down:0 left:1 up:2 right:3
		sf::Color colour;
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::RectangleShape hitbox;
		entity(sf::Vector3f rgb, sf::Vector2f pos, sf::Vector2f size, std::string type);
		entity(sf::Color rgb, sf::Vector2f pos, sf::Vector2f size, std::string type);
		entity() {}
	};
}

#endif // ! SNAKE
