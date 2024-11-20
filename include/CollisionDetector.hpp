#ifndef COLLISIONDETECTOR_HPP
#define COLLISIONDETECTOR_HPP

#include "Shape.hpp"
#include "Vector2.hpp"

class CollisionDetector {
public:
    static bool checkCollision(const Shape& shape1, const Shape& shape2); // Detect collision between two shapes.
    static Vector2 calculateCollisionNormal(const Shape& shape1, const Shape& shape2); // Calculate the collision normal.

private:
    static bool circleVsCircle(const Circle& c1, const Circle& c2);
    static bool rectangleVsRectangle(const Rectangle& r1, const Rectangle& r2);
    static bool circleVsRectangle(const Circle& circle, const Rectangle& rect);
};

#endif // COLLISIONDETECTOR_HPP
