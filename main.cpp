#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include <list>
#include <random>
#include <filesystem>
#include "entity.h"
using namespace std;
using namespace fg;

const int snakeSizeInt = 50;
const sf::Vector2f snakeSize = sf::Vector2f(snakeSizeInt, snakeSizeInt);
const sf::Vector2f fruitSize = sf::Vector2f(snakeSizeInt/2, snakeSizeInt/2);
const sf::Vector3f snakeColour1 = sf::Vector3f(0, 200, 0);
const sf::Vector3f snakeColour2 = sf::Vector3f(82, 5, 10);
const sf::Vector3f snakeColour3 = sf::Vector3f(43, 80, 170);
const sf::Vector3f fruitColour = sf::Vector3f(255,27,28);

const filesystem::path cwd = filesystem::current_path();
const string fontAddress = cwd.string() + "\\Resources\\comicsans\\COMIC.ttf";
//fontAddress += "\\Resources\\comicsans\\COMIC.ttf";

void moveSnake(list<entity> &player) {
	if (player.size() > 1) {
		player.pop_back();
		list<entity>::iterator it = ++player.begin();
		player.insert(it, entity(snakeColour1, snakeSize, player.front().pos, "segment"));
	}
	player.front().move();
}
void draw(sf::RenderWindow& win, list<entity> player1, entity fruit, list<entity> player2 = list<entity>{}, sf::Text p1p, sf::Text p2p) {
	win.clear();
	for (entity i:player1) {
		i.draw(win);
	}
	for (entity i : player2) {
		i.draw(win);
	}
	fruit.draw(win);
	win.display();
}
void runMenu(sf::RenderWindow& win, sf::Font comicsans) {

	sf::Text title;
	title.setString("Snake");
	title.setCharacterSize(200);
	title.setFillColor(sf::Color(0, 200, 0));
	title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	title.setFont(comicsans);
	title.setPosition(sf::Vector2f((win.getSize().x-title.getLocalBounds().width) / 2, ((win.getSize().y - title.getLocalBounds().height) /2) - (win.getSize().y/4)));

	sf::Text startText;
	startText.setString("Press enter to start");
	startText.setCharacterSize(100);
	startText.setFillColor(sf::Color(0, 200, 0));
	startText.setFont(comicsans);
	startText.setPosition(sf::Vector2f((win.getSize().x - startText.getLocalBounds().width) / 2, ((win.getSize().y - startText.getLocalBounds().height) / 2) ));

	win.clear();

	win.draw(title);
	win.draw(startText);

	win.display();
	bool run = true;
	while (win.isOpen() && run) {
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			win.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			run = false;
		}
	}
}


int main() {
	sf::RenderWindow win(sf::VideoMode(200, 200), "SFML Works!", sf::Style::Fullscreen);
	//get the random positions of the fruits
	default_random_engine randGen;
	uniform_int_distribution<int> distX(0, win.getSize().x-snakeSizeInt/2);
	uniform_int_distribution<int> distY(0, win.getSize().y - snakeSizeInt / 2);
	randGen.seed(time(0));

	sf::Vector2f startPos = sf::Vector2f((win.getSize().x - snakeSizeInt) / 2, (win.getSize().y - snakeSizeInt) / 2);
	entity head = entity(snakeColour1, snakeSize, startPos,"head");
	head.setSnake();
	entity fruit = entity(fruitColour, fruitSize, sf::Vector2f(distX(randGen), distY(randGen)),"fruit");
	list<entity> player1;
	player1.push_back(head);

	list<entity> player2;

	bool twoPlayer = false;

	int p1Points = 0;
	int p2Points = 0;


	sf::Font comicsans;
	if (!comicsans.loadFromFile(fontAddress)) {
		cout << "font failed to load" << endl;
		return -1;
	}
	
	sf::Text p1PointsText;
	sf::Text p2PointsText;

	p1PointsText.setString("Points: 0");
	p2PointsText.setString("Points: 0");

	p1PointsText.setCharacterSize(100);
	p1PointsText.setFillColor(sf::Color(200, 0, 0));
	p1PointsText.setFont(comicsans);

	p2PointsText.setCharacterSize(100);
	p2PointsText.setFillColor(sf::Color(200, 0, 0));
	p2PointsText.setFont(comicsans);

	runMenu(win, comicsans);


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
		draw(win,player1,fruit,player2,p1PointsText,p2PointsText);
		moveSnake(player1);
		for (entity i : player1) {
			if (i.collidesWith(player1.front()) && i.type !="head") {
				cout<<"collide"<<endl;
			}
		}

		if (player1.front().collidesWith(fruit)) {//doesn't work
			p1Points++;
			p1PointsText.setString("Points: "+to_string(p1Points));
			fruit.pos=sf::Vector2f(distX(randGen), distY(randGen));
		}
	}
	return 0;
}