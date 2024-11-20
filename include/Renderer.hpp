#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "RigidBody.hpp"
#include <vector>

class Renderer {
public:
    Renderer(); // Constructor for initializing rendering context.

    void draw(const std::vector<RigidBody*>& bodies); // Draw all rigid bodies.
    void drawShape(const Shape& shape); // Draw a single shape.
};

#endif // RENDERER_HPP
