#include "../../include/components/Rigidbody2d/Rigidbody2d.h"
#include<iostream>

Rigidbody2d::Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity, const sf::Vector2f& size, const float& mass)
        : mass(mass), force(0.0f, 98.0f), position(initialPosition), velocity(initialVelocity), size(size) {}

	
sf::Vector2f Rigidbody2d::getVelocity(){
	return velocity;
}

sf::Vector2f Rigidbody2d::getPosition(){
	return position;
}

sf::Vector2f Rigidbody2d::getSize(){
	return size;
}

sf::Vector2f Rigidbody2d::setPosition(sf::Vector2f newPosition){
    position = newPosition;
}

void Rigidbody2d::setVelocity(const sf::Vector2f& newVelocity){
	velocity = newVelocity;
}

void Rigidbody2d::Update(float deltaTime) {
    sf::Vector2f acceleration = force / mass;
    velocity += acceleration * deltaTime;
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
