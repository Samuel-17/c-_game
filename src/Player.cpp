#include "include/Player.h"

Player::Player(float x, float y, float width, float height) :
    position(x, y), width(width), height(height), velocity(x, y), rig(this->position, this->velocity) {}

float Player::getPositionX() {
    return position.x;
}

float Player::getPositionY() {
    return position.y;
}

float Player::getWidth() {
    return width;
}

float Player::getHeight() {
    return height;
}

void Player::update(float deltaTime) {
    rig.Update(deltaTime);
    position.x += rig.getVelocity().x;
    position.y += rig.getVelocity().y;
}

void Player::draw(sf::RenderWindow& window) {
    sf::RectangleShape playerRect(sf::Vector2f(width, height));
    playerRect.setPosition(position.x, position.y);
    playerRect.setFillColor(sf::Color::Blue);
    window.draw(playerRect);
}

float Player::getVelocityX() {
    return velocity.x;
}

float Player::getVelocityY() {
    return velocity.y;
}

void Player::setVelocityX(float x) {
    velocity.x = x;
}

void Player::setVelocityY(float y) {
    velocity.y = y;
}

