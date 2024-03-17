//class Fire
#ifndef FIRE_H
#define FIRE_H

#include<SFML/Graphics.hpp>

class Fire {
  private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::CircleShape shape; 
    int radius;
  
  public:
    Fire(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Vector2f& acceleration, float radius);
    void draw(sf::RenderWindow* window);
    void update(float deltaTime);
};


#endif