#include "../include/entity/Player.h"

Player::Player(float x, float y, float width, float height) :
    position(x, y), size(width, height), velocity(0.0f, 1.0f), rig(position, velocity, size) {}

float Player::getPositionX() {
    return position.x;
}

float Player::getPositionY() {
    return position.y;
}

sf::Vector2f Player::getSize() {
    return size;
}

void Player::update(float deltaTime) {
    rig.Update(deltaTime);
    position += rig.getVelocity();
    rig.move(sf::Vector2f(velocity.x, velocity.y));
}

void Player::draw(sf::RenderWindow& window) {
    sf::RectangleShape playerRect(size);
    playerRect.setPosition(rig.getPosition().x, rig.getPosition().y);
    playerRect.setFillColor(sf::Color::Blue);
    window.draw(playerRect);
}

sf::Vector2f Player::getVelocity() {
    return velocity;
}

void Player::setVelocityX(float x) {
    velocity.x = x;
}

void Player::setVelocityY(float y) {
    velocity.y = y;
}

Rigidbody2d* Player::getRigidbody(){
    return &rig;
}