#include "../include/entity/Player.h"

Player::Player(sf::RenderWindow* window, float x, float y, float width, float height, float mass) :
   window(window),position(x, y), velocity(0.0f, 1.0f), size(width, height), mass(mass), rig(position, velocity, size, mass) {}


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
    velocity = rig.getVelocity();
    position += velocity * deltaTime;

    rig.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) {
    sf::RectangleShape playerRect(size);
    playerRect.setPosition(position.x, position.y);
    playerRect.setFillColor(sf::Color::Blue);
    window.draw(playerRect);
}

sf::Vector2f Player::getVelocity() {
    return velocity;
}

void Player::fire(){
    sf::Vector2f acceleration(0.0f, -10.0f);
    Fire fire(position, sf::Vector2f(5.0f, 0.0f), acceleration, 10.0f);
    fire.draw(window);
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

void Player::handleKeyboardInput(const sf::Event& event) {
    if(event.type == sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::Right) {
            setVelocityX(10.0f);
        } else if (event.key.code == sf::Keyboard::Left) {
            setVelocityX(-10.0f);
        }else if(event.key.code == sf::Keyboard::Space){
            fire();
        }
    } else if(event.type == sf::Event::KeyReleased){
        setVelocityX(0.0f);
    }

    rig.setVelocity(velocity);
}
