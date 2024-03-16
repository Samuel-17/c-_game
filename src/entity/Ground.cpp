#include "../include/entity/Ground.h"
#include "../include/components/Rigidbody2d/Rigidbody2d.h"

Ground::Ground(float x, float y,float width, float height) : 
	position(x, y), velocity(0.0f, 0.0f), size(width, height), rig(position, velocity, size) {}

void Ground::draw(sf::RenderWindow& window){
	sf::RectangleShape groundRect(size);
	groundRect.setPosition(rig.getPosition().x, rig.getPosition().y);
	groundRect.setFillColor(sf::Color::Green);
	window.draw(groundRect);
}

sf::Vector2f Ground::getPosition(){
	return position;
}

float Ground::getWidth(){
	return size.x;
}

float Ground::getHeight(){
	return size.y;
}

Rigidbody2d* Ground::getRigidbody(){
	return &rig;
}