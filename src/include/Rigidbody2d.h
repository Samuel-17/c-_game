#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include <SFML/Graphics.hpp>
	
class Rigidbody2d {
	private:
		float mass;
		float force;
		sf::Vector2f position;
    		sf::Vector2f velocity;
	public:
		Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity);
	void Update(float deltaTime);

	sf::Vector2f getVelocity();

};

#endif

