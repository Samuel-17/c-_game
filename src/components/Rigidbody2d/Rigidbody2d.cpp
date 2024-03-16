#include "../../include/components/Rigidbody2d/Rigidbody2d.h"
#include<iostream>

Rigidbody2d::Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity, const sf::Vector2f& size)
        : force(0.0f, 98.0f), position(initialPosition), velocity(initialVelocity),size(size) {}

	
sf::Vector2f Rigidbody2d::getVelocity(){
	return velocity;
}

sf::Vector2f Rigidbody2d::getPosition(){
	return position;
}

sf::Vector2f Rigidbody2d::getSize(){
	return size;
}

void Rigidbody2d::setVelocity(const sf::Vector2f& newVelocity){
	velocity = newVelocity;
}

void Rigidbody2d::move(const sf::Vector2f& direction){
	setVelocity(direction);
}

void Rigidbody2d::Update(float deltaTime) {
    velocity += force * deltaTime; // Aplica a gravidade à velocidade
    // Limitar a velocidade máxima de queda para evitar que seja muito lenta ou rápida demais
    float maxFallSpeed = 50.0f; // Exemplo de limite máximo de velocidade de queda
    if (velocity.y > maxFallSpeed) {
        velocity.y = maxFallSpeed;
    }
    velocity += velocity * deltaTime; // Atualiza a posição com a nova velocidade
}

void Rigidbody2d::onCollision(const Rigidbody2d& other, CollisionSide side) {
    switch (side) {
        case CollisionSide::LEFT:
            std::cout << "Collision on the LEFT side." << std::endl;
            velocity.x = -velocity.x; // Inverte a direção em x para "quicar" lateralmente
            break;
        case CollisionSide::RIGHT:
            std::cout << "Collision on the RIGHT side." << std::endl;
            velocity.x = -velocity.x; // Inverte a direção em x para "quicar" lateralmente
            break;
        case CollisionSide::TOP:
            std::cout << "Collision at the TOP." << std::endl;
            velocity.y = -velocity.y * 0.8f; // Faz o objeto "quicar" para cima, mas reduz a velocidade para simular perda de energia
            break;
        case CollisionSide::BOTTOM:
            std::cout << "Collision at the BOTTOM." << std::endl;
            velocity.y = -velocity.y * 0.8f; // Inverte a direção em y para "quicar" e reduz a magnitude para simular a perda de energia
            break;
        default:
            std::cout << "Unknown collision side." << std::endl;
    }
}
