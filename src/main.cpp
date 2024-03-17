#include<iostream>
#include<SFML/Graphics.hpp>
#include "include/entity/Player.h"
#include "include/entity/Ground.h"
#include "include/components/Rigidbody2d/Collider/Collider.h"
#include "include/components/Rigidbody2d/Collider/CollisionManager.h"

int main(){

    //Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    Player player(&window, 10.0f, 10.0f, 10.0f, 20.0f, 3.0f);
    Ground ground(0.0f, window.getSize().y - 20.0f, window.getSize().x, 20.0f);

    CollisionManager collisionManager;

    collisionManager.registerRigidbodies(player.getRigidbody());
    collisionManager.registerRigidbodies(ground.getRigidbody());

    sf::Clock clock;

    //Start the game Loop
    while(window.isOpen()){
        //Process events
        sf::Event event;

        while (window.pollEvent(event)) {
            // Close window to exit
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                player.handleKeyboardInput(event);
            }
        }

	    sf::Time elapsed = clock.restart();
	    float deltaTime = elapsed.asSeconds();

        collisionManager.checkCollision();
        
        window.clear();
	    ground.draw(window);
        player.update(deltaTime);
        player.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}

