//class Player
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../components/Rigidbody2d/Rigidbody2d.h"
#include "../components/GameObject/IGameObject.h"
#include "Fire.h"
#include<iostream>

class Player : public IGameObject {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f size;
    sf::RenderWindow* window;
    float mass;

    Rigidbody2d rig;

public:
    Player(sf::RenderWindow* window, float x, float y, float width, float height, float mass);

    //Event
    void handleKeyboardInput(const sf::Event& event) override;

    float getPositionX();
    float getPositionY();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void fire();

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

