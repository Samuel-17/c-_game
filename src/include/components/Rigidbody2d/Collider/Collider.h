#ifndef COLLIDER_H
#define COLLIDER_H

template<typename T, typename U>
class Collider {
public:
    static bool checkCollision(const T& object1, const U& object2);
};

#include "../../../../components/Rigidbody2d/Collider/Collider.tpp" // Include da implementação de templates

#endif

