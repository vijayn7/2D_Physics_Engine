#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Shape.hpp"
#include "Vector2.hpp"

class RigidBody {
public:
    RigidBody(Shape* shape, float mass); // Constructor to initialize with shape and mass.

    void applyForce(const Vector2& force); // Apply an external force.
    void update(float deltaTime); // Update the position and velocity.

    Shape* getShape() const; // Get the shape of the rigid body.
    const Vector2& getPosition() const; // Get the current position.
    void setPosition(const Vector2& position); // Set the position manually.

private:
    Shape* shape; // The shape of the rigid body.
    float mass; // The mass of the body.
    Vector2 position; // Position in the world.
    Vector2 velocity; // Current velocity.
    Vector2 force; // Accumulated forces.
};

#endif // RIGIDBODY_HPP
