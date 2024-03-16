#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../components/Rigidbody2d/Rigidbody2d.h"
#include "Ground.h"

class Player {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f size;

    Rigidbody2d rig;

public:
    Player(float x, float y, float width, float height);

    float getPositionX();
    float getPositionY();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    // Geters
    float getVelocityX();
    float getVelocityY();

    //Seters
    void setVelocityX(float x);
    void setVelocityY(float y);


    sf::Vector2f getSize();
    sf::Vector2f getVelocity();


    Rigidbody2d* getRigidbody();

    
};

#endif

