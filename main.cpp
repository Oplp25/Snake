#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include <vector>
#include "entity.h"
using namespace std;
using namespace fg;
void draw(sf::RenderWindow &win, vector<entity> toDraw) {
	win.clear();
	for (entity i:toDraw) {
		i.draw(win);
	}
	win.display();
}
int main() {
	sf::RenderWindow win(sf::VideoMode(200, 200), "SFML Works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	entity head = entity(sf::Vector3f(0,200,0), sf::Vector2f(10,10),sf::Vector2f(95,95));

	vector<entity> entities;
	entities.push_back(head);
	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win.close();
			}
		}
		draw(win,entities);
	}
	return 0;
}