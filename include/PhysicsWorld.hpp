#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP

#include "RigidBody.hpp"
#include <vector>

class PhysicsWorld {
public:
    PhysicsWorld(); // Constructor to initialize the world.

    void addRigidBody(RigidBody* body); // Add a rigid body to the world.
    void applyGlobalForce(const Vector2& force); // Apply a global force to all bodies.
    void step(float deltaTime); // Perform one physics simulation step.

private:
    std::vector<RigidBody*> bodies; // List of rigid bodies in the world.
    void resolveCollisions(); // Detect and resolve all collisions.
};

#endif // PHYSICSWORLD_HPP
