#include<iostream>
#include<SFML/Graphics.hpp>
#include "./include/Player.h"
#include "include/Ground.h"
#include "include/Collider.h"

int main(){

    //Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    Player player(10.0f, 10.0f, 10.0f, 10.0f);
    Ground ground(0.0f, window.getSize().y - 20.0f, window.getSize().x, 20.0f);

    sf::Clock clock;

    int keyPressed = 0;

    //Start the game Loop
    while(window.isOpen()){
        //Process events
        sf::Event event;

        while (window.pollEvent(event)) {
            // Close window to exit
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    keyPressed = 1;
                } else if (event.key.code == sf::Keyboard::Left) {
                    keyPressed = 2;
                }
            } else if (event.type == sf::Event::KeyReleased) {
                keyPressed = 0;
            }
        }

	sf::Time elapsed = clock.restart();
	float deltaTime = elapsed.asSeconds();

        switch(keyPressed){
            case 1:
                player.setVelocityX(2.2f);
                break;
            case 2:
                player.setVelocityX(-2.2f);
                break;
            default:
                player.setVelocityX(0.0f);
                break;
        }

	Collider<Player, Ground>::checkCollision(player, ground);
        window.clear();
	ground.draw(window);
        player.update(deltaTime);
        player.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}

