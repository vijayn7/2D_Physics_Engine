#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "RigidBody.hpp"

class Solver {
public:
    static void resolveCollision(RigidBody& body1, RigidBody& body2); // Resolve collision between two rigid bodies.
    static void applyImpulse(RigidBody& body, const Vector2& impulse); // Apply an impulse to a body.
};

#endif // SOLVER_HPP
