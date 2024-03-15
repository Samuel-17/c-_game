// Class Ground
#ifndef GROUND_H
#define GROUND_H

#include<SFML/Graphics.hpp>
#include "../components/Rigidbody2d/Rigidbody2d.h"

class Ground {
	private:
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f size;
    Rigidbody2d rig;

	public:
		Ground(float x, float y, float width, float height);
		void draw(sf::RenderWindow& window);
		float getWidth();
		float getHeight(); 
		sf::Vector2f getPosition();

		//Rigidbody2d
		Rigidbody2d* getRigidbody();
		
};


#endif
