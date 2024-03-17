#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class IGameObject {
  public:
    virtual ~IGameObject() = default;
    virtual void handleKeyboardInput(const sf::Event& event) = 0;
};

#endif