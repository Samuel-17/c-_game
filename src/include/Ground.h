// Class Ground
#ifndef GROUND_H
#define GROUND_H

#include<SFML/Graphics.hpp>

class Ground {
	private:
		float x;
		float y;
		float width;
	       	float height;
	public:
		Ground(float x, float y, float width, float height);
		void draw(sf::RenderWindow& window);
};


#endif
