#include "Shape.hpp"
#include "Vector2.hpp"
#include "RigidBody.hpp"

RigidBody::RigidBody(Shape* shape, float mass) : shape(shape), mass(mass) {}

void RigidBody::applyForce(const Vector2& force) {
    this->force += force;
}