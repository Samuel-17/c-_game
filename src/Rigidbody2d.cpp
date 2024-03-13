#include "include/Rigidbody2d.h"


Rigidbody2d::Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity)
        : position(initialPosition), velocity(initialVelocity) {}

	
sf::Vector2f Rigidbody2d::getVelocity(){
	return velocity;
}

void Rigidbody2d::Update(float deltaTime) {
        position += velocity * deltaTime;
}

