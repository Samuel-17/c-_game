#include "../../include/components/Rigidbody2d/Rigidbody2d.h"
#include<iostream>

Rigidbody2d::Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity, const sf::Vector2f& size)
        : force(0.0f, 98.0f), position(initialPosition), velocity(initialVelocity),size(size) {}

	
sf::Vector2f Rigidbody2d::getVelocity(){
	return velocity;
}

sf::Vector2f Rigidbody2d::getPosition(){
	return position;
}

sf::Vector2f Rigidbody2d::getSize(){
	return size;
}

void Rigidbody2d::setVelocity(const sf::Vector2f& newVelocity){
	velocity = newVelocity;
}

void Rigidbody2d::move(const sf::Vector2f& direction){
	setVelocity(direction);
}

void Rigidbody2d::Update(float deltaTime) {
    velocity += force * deltaTime; 
    float maxFallSpeed = 50.0f;
    if (velocity.y > maxFallSpeed) {
        velocity.y = maxFallSpeed;
    }
    velocity += velocity * deltaTime; 
}

void Rigidbody2d::onCollision(const Rigidbody2d& other, CollisionSide side) {
    switch (side) {
        case CollisionSide::LEFT:
            std::cout << "Collision on the LEFT side." << std::endl;
            velocity.x = -velocity.x; 
            break;
        case CollisionSide::RIGHT:
            std::cout << "Collision on the RIGHT side." << std::endl;
            velocity.x = -velocity.x; 
            break;
        case CollisionSide::TOP:
            std::cout << "Collision at the TOP." << std::endl;
            velocity.y = -velocity.y * 0.8f;
            break;
        case CollisionSide::BOTTOM:
            std::cout << "Collision at the BOTTOM." << std::endl;
            velocity.y = -velocity.y * 0.8f; 
            break;
        default:
            std::cout << "Unknown collision side." << std::endl;
    }
}
