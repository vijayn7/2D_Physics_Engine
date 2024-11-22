#include "Shape.hpp"
#include <iostream>

// Circle Implementation
Circle::Circle(std::pair<float, float> position, float radius) :
    Shape(position, {radius * 2, radius * 2}), radius(radius) {}

bool Circle::intersects(const Shape& other) const {
    // Check if the other shape is a circle.
    if (const Circle* circle = dynamic_cast<const Circle*>(&other)) {
        // Calculate the distance between the two circles.
        float dx = circle->getX() - getX();
        float dy = circle->getY() - getY();
        float distance = std::sqrt(dx * dx + dy * dy);

        // Check if the distance is less than the sum of the radii.
        return distance < radius + circle->radius;
    }

    // Check if the other shape is a rectangle.
    if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(&other)) {
        // Calculate the closest point on the rectangle to the circle.
        float closestX = std::clamp(getX(), rectangle->getX(), rectangle->getX() + rectangle->getWidth());
        float closestY = std::clamp(getY(), rectangle->getY(), rectangle->getY() + rectangle->getHeight());

        // Calculate the distance between the circle and the closest point.
        float dx = closestX - getX();
        float dy = closestY - getY();
        float distance = std::sqrt(dx * dx + dy * dy);

        // Check if the distance is less than the radius.
        return distance < radius;
    }

    // The other shape is not a circle or rectangle.
    return false;
}

void Circle::debugDraw() const {
    std::cout << "Circle at (" << getX() << ", " << getY() << ") with radius " << radius << std::endl;
}

// Rectangle Implementation

Rectangle::Rectangle(std::pair<float, float> position, std::pair<float, float> size) :
    Shape(position, size) {}

bool Rectangle::intersects(const Shape& other) const {
    // Check if the other shape is a circle.
    if (const Circle* circle = dynamic_cast<const Circle*>(&other)) {
        // Calculate the closest point on the rectangle to the circle.
        float closestX = std::clamp(circle->getX(), getX(), getX() + getWidth());
        float closestY = std::clamp(circle->getY(), getY(), getY() + getHeight());

        // Calculate the distance between the circle and the closest point.
        float dx = closestX - circle->getX();
        float dy = closestY - circle->getY();
        float distance = std::sqrt(dx * dx + dy * dy);

        // Check if the distance is less than the radius.
        return distance < circle->getRadius();
    }

    // Check if the other shape is a rectangle.
    if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(&other)) {
        // Calculate the overlap between the two rectangles.
        float overlapX = std::min(getX() + getWidth(), rectangle->getX() + rectangle->getWidth()) - std::max(getX(), rectangle->getX());
        float overlapY = std::min(getY() + getHeight(), rectangle->getY() + rectangle->getHeight()) - std::max(getY(), rectangle->getY());

        // Check if the overlap is positive in both dimensions.
        return overlapX > 0 && overlapY > 0;
    }

    // The other shape is not a circle or rectangle.
    return false;
}

void Rectangle::debugDraw() const {
    std::cout << "Rectangle at (" << getX() << ", " << getY() << ") with size (" << getWidth() << ", " << getHeight() << ")" << std::endl;
}