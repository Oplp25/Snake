#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include <list>
#include "entity.h"
using namespace std;
using namespace fg;

const int snakeSizeInt = 50;
const sf::Vector2f snakeSize = sf::Vector2f(snakeSizeInt, snakeSizeInt);
const sf::Vector3f snakeColour1 = sf::Vector3f(0, 200, 0);
const sf::Vector3f snakeColour2 = sf::Vector3f(82, 5, 10);
const sf::Vector3f snakeColour3 = sf::Vector3f(43, 80, 170);

void moveSnake(list<entity> &player) {
	if (player.size() > 1) {
		player.pop_back();
		list<entity>::iterator it = ++player.begin();
		player.insert(it, entity(snakeColour1, snakeSize, player.front().pos));
	}
	player.front().move();
}
void draw(sf::RenderWindow &win, list<entity> toDraw) {
	win.clear();
	for (entity i:toDraw) {
		i.draw(win);
	}
	win.display();
}
int main() {
	sf::RenderWindow win(sf::VideoMode(200, 200), "SFML Works!",sf::Style::Fullscreen);

	sf::Vector2f startPos = sf::Vector2f((win.getSize().x- snakeSizeInt)/2, (win.getSize().y- snakeSizeInt)/2);
	entity head = entity(snakeColour1, snakeSize, startPos);
	head.setSnake();
	list<entity> player1;
	player1.push_back(head);
	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player1.front().setDirection(2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player1.front().setDirection(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player1.front().setDirection(0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player1.front().setDirection(3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			win.close();
		}
		draw(win,player1);
		moveSnake(player1);
	}
	return 0;
}