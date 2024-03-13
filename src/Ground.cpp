#include "include/Ground.h"

Ground::Ground(float x, float y, float width, float height) : 
	x(x), y(y), width(width), height(height) {}

void Ground::draw(sf::RenderWindow& window){
	sf::RectangleShape groundRect(sf::Vector2f(width, height));
	groundRect.setPosition(x, y);
	groundRect.setFillColor(sf::Color::Blue);
	window.draw(groundRect);
}
