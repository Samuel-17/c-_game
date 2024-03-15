#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include<iostream>
#include "../Rigidbody2d.h"
#include "CollisionSide.h"

class CollisionManager {
  private:
    std::vector<Rigidbody2d*> rigidbodies;

  public:
    void registerRigidbodies(Rigidbody2d* rb);
    void checkCollision();
};


#endif