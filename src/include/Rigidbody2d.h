#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "Player.h"
#include <SFML/Graphics.hpp>
	
class Rigidbody2d {
	private:
		float mass;
		float force;
		sf::Vector2f position;
    		sf::Vector2f velocity;
	public:
		Rigidbody2d(const sf::Vector2f& initialPosition, const sf::Vector2f& initialVelocity);
	void Update(float deltaTime);

	sf::Vector2f getVelocity();

};

//class Physics {
//private:
//    Player& player; // Referência para o jogador
//    float gravity;  // Força da gravidade

//public:
//    Physics(Player& player, float gravity); // Construtor que recebe uma referência para o jogador e a força da gravidade

//    void applyPhysics(); // Método para aplicar a física ao jogador
//};

#endif

