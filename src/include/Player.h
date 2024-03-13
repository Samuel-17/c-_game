#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Rigidbody2d.h"

class Player {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float width;
    float height;

    Rigidbody2d rig;

public:
    Player(float x, float y, float width, float height);

    float getPositionX();
    float getPositionY();
    float getWidth();
    float getHeight();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    // Métodos para obter e definir velocidades
    float getVelocityX();
    float getVelocityY();
    void setVelocityX(float x);
    void setVelocityY(float y);
};

#endif

