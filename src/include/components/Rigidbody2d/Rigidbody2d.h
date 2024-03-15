#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include <SFML/Graphics.hpp>
#include "Collider/CollisionSide.h"

class Rigidbody2d {
	private:
		float mass;
		sf::Vector2f force;

		sf::Vector2f position;
    sf::Vector2f velocity;
		sf::Vector2f size;
	
	public:
		Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity, const sf::Vector2f& size);
		void Update(float deltaTime);
		void onCollision(const Rigidbody2d& other, CollisionSide side);

		//Velocity(x, y)
		sf::Vector2f getVelocity();
		sf::Vector2f getPosition();
		sf::Vector2f getSize();

		void setVelocity(const sf::Vector2f& newVelocity);
		void move(const sf::Vector2f& direction);
};

#endif

