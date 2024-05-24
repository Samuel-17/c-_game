#include<iostream>
#include "../../../include/components/Rigidbody2d/Collider/CollisionManager.h"

void CollisionManager::registerRigidbodies(Rigidbody2d* rb){
  rigidbodies.push_back(rb);
}

void CollisionManager::checkCollision() {
    for (size_t i = 0; i < rigidbodies.size(); ++i) {
        for (size_t j = i + 1; j < rigidbodies.size(); ++j) {
            Rigidbody2d* rb1 = rigidbodies[i];
            Rigidbody2d* rb2 = rigidbodies[j];

            sf::Vector2f pos1 = rb1->getPosition();
            sf::Vector2f size1 = rb1->getSize();
            sf::Vector2f pos2 = rb2->getPosition();
            sf::Vector2f size2 = rb2->getSize();

        
            bool overlapX = pos1.x + size1.x > pos2.x && pos2.x + size2.x > pos1.x;
            bool overlapY = pos1.y + size1.y > pos2.y && pos2.y + size2.y > pos1.y;

            if (overlapX && overlapY) {
     
                float overlapXValue = std::min(pos1.x + size1.x, pos2.x + size2.x) - std::max(pos1.x, pos2.x);
                float overlapYValue = std::min(pos1.y + size1.y, pos2.y + size2.y) - std::max(pos1.y, pos2.y);

                CollisionSide side;
          
                if (overlapXValue < overlapYValue) {
                    side = (pos1.x < pos2.x) ? CollisionSide::RIGHT : CollisionSide::LEFT;
                } else {
                    side = (pos1.y < pos2.y) ? CollisionSide::BOTTOM : CollisionSide::TOP;
                }

                rb1->onCollision(*rb2, side);
                rb2->onCollision(*rb1, side);
            }
        }
    }
}
