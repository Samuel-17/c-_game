#include "../include/entity/Fire.h"

Fire::Fire(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Vector2f& acceleration, float radius)
        : position(position), velocity(velocity), acceleration(acceleration) {
            shape.setRadius(radius);
            shape.setPosition(position);
            shape.setFillColor(sf::Color::Red);
        }

void Fire::draw(sf::RenderWindow* window){
  window->draw(shape);
}

void Fire::update(float deltaTime) {
  velocity += acceleration * deltaTime; 
  position += velocity * deltaTime; 
  shape.setPosition(position);
}
